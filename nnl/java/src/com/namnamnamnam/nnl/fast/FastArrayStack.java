package com.namnamnamnam.nnl.fast;

import com.namnamnamnam.nnl.ArrayStack;

public class FastArrayStack<T> extends ArrayStack<T> {
  public FastArrayStack(Class<T> t) {
    super(t);
  }

  @Override
  public void add(int i, T x) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    if (a.length < n + 1)
      resize();
    System.arraycopy(a, i, a, i + 1, n - i);
    a[i] = x;
    n++;
  }

  @Override
  public T remove(int i) {
		if (i < 0 || i > n)
      throw new IndexOutOfBoundsException();
    T x = a[i];
    System.arraycopy(a, i + 1, a, i, n - i - 1);
    n--;
    if (a.length > 3 * n)
      resize();
    return x;
  }

  @Override
  protected void resize() {
    T[] b = gaf.newInstance(Math.max(2 * n, 1));
    System.arraycopy(a, 0, b, 0, n);
    a = b;
  }
}
