#pragma once
template <typename T>
struct dnode{
    dnode<T> *pre;
    T data;
    dnode<T> *next;
};
