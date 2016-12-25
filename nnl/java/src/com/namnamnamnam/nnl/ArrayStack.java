package com.namnamnamnam.nnl;

public class ArrayStack<T> implements List<T> {
  T[] a;
  int n;

  public ArrayStack() {
    a = new T[1];
    n = 0;
  }

  public int size() {
    return n;
  }

  public T get(int i) {
    return a[i];
  }

  public void set(int i, T x) {
    a[i] = x;
  }

  public void add(int i, T x) {
    if (n + 1 > a.length)
      resize();
    for (int j = n; j > i; j--)
      a[j] = a[j - 1];
    a[i] = x;
    n++;
  }

  public T remove(int i) {
    T x = a[i];
    for (int j = i; j < n - 1; j++)
      a[j] = a[j + 1];
    n--;
    if (a.length >= 3 * n)
      resize();
    return x;
  }

  private void resize() {
    T[] b = new T[Math.max(2 * n, 1)];
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    a = b;
  }
}
