package com.namnamnamnam.nnl;

import java.lang.reflect.Array;

public class GenericArrayFactory<T> {
  Class<T> t;

  public GenericArrayFactory(Class<T> classType) {
    t = classType;
  }

  @SuppressWarnings({"unchecked"})
  public T[] newInstance(int n) {
    return (T[])Array.newInstance(t, n);
  }
}
