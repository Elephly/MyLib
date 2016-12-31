package com.namnamnamnam.nnl;

public class ArrayStack<T> implements List<T> {
  protected GenericArrayFactory<T> gaf;
  protected T[] a;
  protected int n;

  public ArrayStack(Class<T> t) {
    gaf = new GenericArrayFactory<T>(t);
    a = gaf.newInstance(1);
    n = 0;
  }

  public int size() {
    return n;
  }

  public T get(int i) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    return a[i];
  }

  public void set(int i, T x) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    a[i] = x;
  }

  public void add(int i, T x) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    if (a.length < n + 1)
      resize();
    for (int j = n; j > i; j--)
      a[j] = a[j - 1];
    a[i] = x;
    n++;
  }

  public T remove(int i) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    T x = a[i];
    for (int j = i; j < n - 1; j++)
      a[j] = a[j + 1];
    n--;
    if (a.length > 3 * n)
      resize();
    return x;
  }

  protected void resize() {
    T[] b = gaf.newInstance(Math.max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    a = b;
  }
}
