#ifndef util_hpp
#define util_hpp

#include <deque>
#include <pthread.h>
#include <iostream>
#include <sstream>
#include <cxxabi.h>

std::string NAME__(const char*);
#define RNAME(x) NAME__(typeid(x).name())

#ifdef WINDOWS
	#include <windows.h>
	#define COUNTER volatile LONG
#else
	#define COUNTER int
#endif

#include <vector>
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& x) {
    out << "{std::vector<" << RNAME(T) << ">}[";
    for(auto i = x.begin(); i!=x.end(); i++) {
        if(i!=x.begin()) out << ", ";
        out << *i;
    }
    return out << "]";
}

class Thread {
private:
    static void* _run(void* target) {
        return (void*)((Thread*)(target))->run();
    }

protected:
    pthread_t thread;

    virtual size_t run() = 0;

public:
    Thread() {}

    void start() {
        pthread_create(&thread,NULL,_run,this);
    }
    size_t wait() {
        void* ret;
        pthread_join(thread,&ret);
        return (size_t)ret;
    }

    void exit(size_t code) {
        pthread_exit((void*)code);
    }
};

//--------------------------------------------------------------------------------------------------

class Mutex {
private:
    pthread_mutex_t mutex;

public:
    Mutex() {
        mutex = PTHREAD_MUTEX_INITIALIZER;
    }

    inline void acquire() { pthread_mutex_lock(&mutex); }
    inline void release() { pthread_mutex_unlock(&mutex); }
    inline bool trylock() { return pthread_mutex_trylock(&mutex)==0; }
};

//--------------------------------------------------------------------------------------------------

template <typename T>
class tsDeque {
protected:

    pthread_cond_t cond;
    pthread_mutex_t mutex;

public:
    std::deque<T> list;

    tsDeque() {
        pthread_cond_init(&cond,NULL);
        mutex = PTHREAD_MUTEX_INITIALIZER;
    }

    void push(const T& dat) {
        pthread_mutex_lock(&mutex);
        list.push_back(dat);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }

    T pop() {
        pthread_mutex_lock(&mutex);
        while(list.empty()) pthread_cond_wait(&cond,&mutex);
        T ret = list.front();
        list.pop_front();
        pthread_mutex_unlock(&mutex);
        return ret;
    }

    bool try_pop(T* store) {
        pthread_mutex_lock(&mutex);
        if(list.empty()) {
            pthread_mutex_unlock(&mutex);
            return false;
        }
        *store = list.front();
        list.pop_front();
        pthread_mutex_unlock(&mutex);
        return true;
    }

    template <typename S>
    friend std::ostream& operator<<(std::ostream&, tsDeque<S>&);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, tsDeque<T>& xs) {
    pthread_mutex_lock(&xs.mutex);
    out << RNAME(tsDeque<T>) << "[";
    for(auto i = xs.list.begin(); i!=xs.list.end(); i++) {
        if(i!=xs.list.begin()) out << ", ";
        out << *i;
    }
    out << "]";
    pthread_mutex_unlock(&xs.mutex);
    return out;
}

//--------------------------------------------------------------------------------------------------

struct ptr_base {
    virtual ~ptr_base() {}
    virtual std::string print() { return "#"; }
};

template <typename T>
struct ptr_data : public ptr_base {
    T* data;

    ~ptr_data() {
        delete data;
    }
    ptr_data(T* data) {
        this->data = data;
    }

    std::string print() {
        std::stringstream str;
        if(data!=NULL)
            str << "ptr<" << RNAME(T) << ">(" << *data << ")";
        else
            str << "ptr<" << RNAME(T) << ">::null";
        return str.str();
    }
};
//--------------------------------------------------------------------------------------------------
inline int __atomic_dec(COUNTER* val) {
#ifdef WINDOWS
	return InterlockedDecrement(val);
#else
	return __sync_sub_and_fetch(count, 1)
#endif
}
inline void __atomic_inc(COUNTER* val) {
#ifdef WINDOWS
	InterlockedIncrement(val);
#else
	__sync_add_and_fetch(count, 1);
#endif
}

//--------------------------------------------------------------------------------------------------

template <typename T>
class ptr {
protected:
    template <typename S>
    friend class ptr;

    template <typename S>
    friend std::ostream& operator<<(std::ostream&, const ptr<S>&);

    COUNTER* count;

    ptr_data<T>* data;

    void free() {
        if(count!=NULL) {
            if(__atomic_dec(count)==0) {
                delete data;
                delete count;
            }
            count = NULL;
        }
        data = NULL;
    }

public:

    ptr() {
        data = NULL;
        count = NULL;
    }

    ptr(T* datum) {
        if(datum!=NULL) {
            data = new ptr_data<T>(datum);
            count = new COUNTER(0);
            __atomic_inc(count);
        }else {
            data = NULL;
            count = NULL;
        }
    }

    ptr(const ptr<T>& x) {
        if(x.data!=NULL) {
            data = x.data;
            count = x.count;
            __atomic_inc(count);
        }else {
            data = NULL;
            count = NULL;
        }
    }
    ptr(const ptr<void>& x);

    ptr<T>& operator=(const ptr<T>& x) {
        if(operator!=(x)) {
            free();
            if(x.data!=NULL) {
                data = x.data;
                count = x.count;
                __atomic_inc(count);
            }
        }
        return *this;
    }
    ptr<T>& operator=(const ptr<void>& x);

    ~ptr() {
        free();
    }

    template <typename S>
    bool operator==(const ptr<S>& x) const { return (size_t) data == (size_t) x.data; }
    template <typename S>
    bool operator!=(const ptr<S>& x) const { return (size_t) data != (size_t) x.data; }

    T* operator->() { return data->data; }
    const T* operator->() const { return data->data; }
    T& operator* () { return *(data->data); }
    const T& operator*() const { return *(data->data); }

    static ptr<T> null;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const ptr<T>& x) {
    if(x.data!=NULL)
        return out << RNAME(ptr<T>) << "(" << (*x) << ")";
    else
        return out << RNAME(ptr<T>) << "::null";
}

template <typename T>
ptr<T> ptr<T>::null;

//--------------------------------------------------------------------------------------------------

template<>
class ptr<void> {
protected:
    template <typename S>
    friend class ptr;

    friend std::ostream& operator<<(std::ostream&, const ptr<void>&);

    COUNTER *count;
    ptr_base* data;

    void free() {
        if(count!=NULL) {
            if(__atomic_dec(count)==0) {
                delete data;
                delete count;
            }
            count = NULL;
        }
        data = NULL;
    }

public:

    ptr() {
        data = NULL;
        count = NULL;
    }

    template <typename T>
    ptr(const ptr<T>& x) {
        if(x.data!=NULL) {
            data = (ptr_base*) x.data;
            count = x.count;
            __atomic_inc(count);
        }else {
            data = NULL;
            count = NULL;
        }
    }

    ptr(const ptr<void>& x) {
        if(x.data!=NULL) {
            data = x.data;
            count = x.count;
            __atomic_inc(count);
        }else {
            data = NULL;
            count = NULL;
        }
    }

    //only for Dynamic
    template <typename T>
    ptr(const T& x) {
        T* xn = new T(x);
        data = (ptr_base*) new ptr_data<T>(xn);
        count = new COUNTER(0);
        __atomic_inc(count);
    }

    //only for Dynamic
    template <typename T>
    ptr<void>& operator=(const T& x) {
        free();
        T* xn = new T(x);
        data = (ptr_base*) new ptr_data<T>(xn);
        count = new COUNTER(0);
        __atomic_inc(count);
        return *this;
    }

    //only for Dynamic
    template <typename T>
    ptr(T* x) {
        data = (ptr_base*) new ptr_data<T>(x);
        count = new COUNTER(0);
        __atomic_inc(count);
    }

    //only for Dynamic
    template <typename T>
    ptr<void>& operator=(T* x) {
        free();
        data = (ptr_base*) new ptr_data<T>(x);
        count = new COUNTER(0);
        __atomic_inc(count);
        return *this;
    }

    //only for Dynamic
    template <typename T>
    /*explicit*/ operator T() { return *(ptr<T>(*this)); }

    template <typename T>
    /*explicit*/ operator T&() { return *(ptr<T>(*this)); }
    template <typename T>
    T& cast() { return *(ptr<T>(*this)); }

    template <typename T>
    ptr<void>& operator=(const ptr<T>& x) {
        if(operator!=(x)) {
            free();
            if(x.data!=NULL) {
                data = (ptr_base*) x.data;
                count = x.count;
                __atomic_inc(count);
            }
        }
        return *this;
    }
    ptr<void>& operator=(const ptr<void>& x) {
        if(operator!=(x)) {
            free();
            if(x.data!=NULL) {
                data = x.data;
                count = x.count;
                __atomic_inc(count);
            }
        }
        return *this;
    }

    ~ptr() {
        free();
    }

    template <typename S>
    bool operator==(const ptr<S>& x) const { return (size_t) data == (size_t) x.data; }
    template <typename S>
    bool operator!=(const ptr<S>& x) const { return (size_t) data != (size_t) x.data; }

    static ptr<void> null;
};

typedef ptr<void> Dynamic;

std::ostream& operator<<(std::ostream& out, const ptr<void>& x);

template <typename T>
ptr<T>::ptr(const ptr<void>& x) {
    if(x.data!=NULL) {
        data = (ptr_data<T>*) x.data;
        count = x.count;
        __atomic_inc(count);
    }else {
        data = NULL;
        count = NULL;
    }
}

template <typename T>
ptr<T>& ptr<T>::operator=(const ptr<void>& x) {
    if(operator!=(x)) {
        free();
        if(x.data!=NULL) {
            data = (ptr_data<T>*) x.data;
            count = x.count;
            __atomic_inc(count);
        }
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------

template <typename T>
class ref {
protected:
    T* data;

    template <typename S>
    friend std::ostream& operator<<(std::ostream&,const ref<S>&);

public:
    ref() {
        data = NULL;
    }
    ref(const ref<T>& x) {
        data = x.data;
    }
    ref(T& x) {
        data = &x;
    }

    T* operator->() { return data; }
    const T* operator->() const { return data; }
    T& operator*() { return *data; }
    const T& operator*() const { return *data; }

    template <typename S>
    bool operator==(const ref<S>& x) const { return (size_t) data == (size_t) x.data; }
    template <typename S>
    bool operator!=(const ref<S>& x) const { return (size_t) data != (size_t) x.data; }

    static ref<T> null;
};

template <typename T>
ref<T> ref<T>::null;

template <typename T>
std::ostream& operator<<(std::ostream& out, const ref<T>& x) {
    if(x.data==NULL)
        return out << RNAME(ref<T>) << "::null";
    else
        return out << RNAME(ref<T>) << "(" << (*x) << ")";
}

#endif
