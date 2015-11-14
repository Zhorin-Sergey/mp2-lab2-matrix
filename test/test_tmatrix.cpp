#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> a(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      a[i][j] = i * 10 + j;
  TMatrix<int> b(a);
  EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> a(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      a[i][j] = i * 10 + j;
  TMatrix<int> b(a);
  b[1][1] = 666;
  EXPECT_NE(a, b);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
 TMatrix<int> v(4);
  v[0][0] = 4;
  EXPECT_EQ(4, v[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> v(5);
  ASSERT_ANY_THROW(v[1][-1] = 322);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> v(5);
  ASSERT_ANY_THROW(v[6][1] = 322);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> v(5), v1(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++) {
	  v[i][j] = i * 10 + j;
	  v1[i][j] = i * 10 + j;
  }
  v = v;
  EXPECT_EQ(v, v1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> v(5), v1(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++) {
      v[i][j] = i * 10 + j;
    }
  v1 = v;
  EXPECT_EQ(v, v1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> v(5), v1(6);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      v[i][j] = i * 10 + j;
  v1 = v;
  EXPECT_EQ(v.GetSize(), v1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> v(5), v1(6);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      v[i][j] = i * 10 + j;
  v1 = v;
  EXPECT_EQ(v, v1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> v(5), v1(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      v[i][j] = i * 10 + j;
  v1 = v;
  EXPECT_EQ(true, v == v1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> v(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
      v[i][j] = i * 10 + j;
  EXPECT_EQ(true, v == v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> v(5), v1(6);
  EXPECT_EQ(false, v1 == v);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> a(5), b(5),c(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
	  c[i][j] = (((i * 10 + j) * 100) + (i * 10 + j));
    }
  EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> v(5), v1(6);
  ASSERT_ANY_THROW(v1 + v);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> a(5), b(5), c(5);
  for (int i = 0; i < 5; i++)
    for (int j = i; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
	  c[i][j] = (((i * 10 + j) - (i * 10 + j) * 100));
    }
  EXPECT_EQ(c, a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> v(5), v1(6);
  ASSERT_ANY_THROW(v1 - v);
}

