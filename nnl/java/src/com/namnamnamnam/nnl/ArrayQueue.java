package com.namnamnamnam.nnl;

import java.util.NoSuchElementException;

public class ArrayQueue<T> implements Queue<T> {
  protected GenericArrayFactory<T> gaf;
  protected T[] a;
  protected int j;
  protected int n;

  public ArrayQueue(Class<T> t) {
    gaf = new GenericArrayFactory<T>(t);
    a = gaf.newInstance(1);
    j = 0;
    n = 0;
  }

  public void add(T x) {
    if (n + 1 > a.length)
      resize();
    a[(j + n) % a.length] = x;
    n++;
  }

  public T remove() {
    if (n == 0) throw new NoSuchElementException();
    T x = a[j];
    j = (j + 1) % a.length;
    n--;
    if (a.length >= 3 * n)
      resize();
    return x;
  }

  protected void resize() {
    T[] b = gaf.newInstance(Math.max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[(i + j) % a.length];
    a = b;
    j = 0;
  }
}
