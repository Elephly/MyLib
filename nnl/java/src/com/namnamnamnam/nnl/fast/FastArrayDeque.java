package com.namnamnamnam.nnl.fast;

import com.namnamnamnam.nnl.ArrayDeque;

public class FastArrayDeque<T> extends ArrayDeque<T> {
  public FastArrayDeque(Class<T> t) {
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
