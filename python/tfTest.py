import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd



try:
  tf.contrib.eager.enable_eager_execution()
except ValueError:
  pass  # enable_eager_execution errors after its first call

tensor = tf.constant('?')
tensor_value = tensor.numpy()
print(tensor_value)

initialization = tf.global_variables_initializer()

g = tf.Graph()
with g.as_default():
    x = tf.constant([1, 3], name='x')
    y = tf.constant([2, 3], name='y')
    sum = tf.add(x, y, 'Sum')
    z = tf.constant([2, 2], name='z')
    sum3 = tf.add(sum, z, 'Sum3')

    with tf.Session() as sess:
        print(sum3.eval())

a = tf.Variable([[[1, 1], [1, 1], [1, 1]], [[1, 1], [1, 1], [1, 1]]])
b = tf.Variable([[1, 2], [3, 4], [5, 6]])
initialization = tf.global_variables_initializer()
print(a * b)

# Task: Simulate 10 throws of two dice. Store the results in a 10x3 matrix.

die1 = tf.contrib.eager.Variable(
    tf.random_uniform([10, 1], minval=1, maxval=7, dtype=tf.int32))
die2 = tf.contrib.eager.Variable(
    tf.random_uniform([10, 1], minval=1, maxval=7, dtype=tf.int32))

dice_sum = tf.add(die1, die2)
resulting_matrix = tf.concat(values=[die1, die2, dice_sum], axis=1)

print(resulting_matrix.numpy())
