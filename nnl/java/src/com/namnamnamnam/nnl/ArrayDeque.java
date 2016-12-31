package com.namnamnamnam.nnl;

public class ArrayDeque<T> implements List<T> {
  protected GenericArrayFactory<T> gaf;
  protected T[] a;
  protected int j;
  protected int n;

  public ArrayDeque(Class<T> t) {
    gaf = new GenericArrayFactory<T>(t);
    a = gaf.newInstance(1);
    j = 0;
    n = 0;
  }

  public int size() {
    return n;
  }

  public T get(int i) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    return a[(i + j) % a.length];
  }

  public void set(int i, T x) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    a[(i + j) % a.length] = x;
  }

  public void add(int i, T x) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    if (a.length < n + 1)
      resize();
    if (i < n / 2) {
      j = (j == 0) ? a.length - 1 : j - 1;
      for (int k = 0; k < i - 1; k++)
        a[(j + k) % a.length] = a[(j + k + 1) % a.length];
    } else {
      for (int k = n; k > i; k--)
        a[(j + k) % a.length] = a[(j + k - 1) % a.length];
    }
    a[(j + i) % a.length] = x;
    n++;
  }

  public T remove(int i) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    T x = a[(j + i) % a.length];
    if (i < n / 2) {
      for (int k = i; k > 0; k--)
        a[(j + k) % a.length] = a[(j + k - 1) % a.length];
      j = (j + 1) % a.length;
    } else {
      for (int k = i; k < n - 1; k++)
        a[(j + k) % a.length] = a[(j + k + 1) % a.length];
    }
    n--;
    if (a.length > 3 * n)
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
