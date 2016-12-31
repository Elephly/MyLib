package com.namnamnamnam.nnl.fast;

import com.namnamnamnam.nnl.ArrayQueue;

public class FastArrayQueue<T> extends ArrayQueue<T> {
  public FastArrayQueue(Class<T> t) {
    super(t);
  }

  @Override
  protected void resize() {
    T[] b = gaf.newInstance(Math.max(2 * n, 1));
    System.arraycopy(a, j, b, 0, n - j);
    System.arraycopy(a, 0, b, n - j, n - (n - j));
    a = b;
    j = 0;
  }
}
