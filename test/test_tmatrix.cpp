#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(7));
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
	TMatrix<int> m(3);
	m[1][1] = 4;
	TMatrix<int> m1(m);

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(3);

	m[1][1] = 1;

	TMatrix<int> m1(m);

	m1[1][1] = 2;

	EXPECT_NE(m1, m);
}

TEST(TMatrix, can_get_size)
{
	int size = 2;

	TMatrix<int> m(size);

	int res = m.GetSize();

	EXPECT_EQ(res, size);
}

TEST(TMatrix, can_set_and_get_element)
{
	int res = 4;
	TMatrix<int> m(2);

	m[1][1] = res;

	EXPECT_EQ(res, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m;
	ASSERT_ANY_THROW(m[-99]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m;
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(7);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int size = 12;
	TMatrix<int> m(size);
	TMatrix<int> m1(size);
	m = m1;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int size = 8; int size1 = size + 1;
	TMatrix<int> m(size);
	TMatrix<int> m1(size1);
	m = m1;
	EXPECT_EQ(size1, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	int size = 7;
	TMatrix<int> m(size);
	TMatrix<int> m1(size + 1);
	m = m1;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int size = 6;
	TMatrix<int> m(size);
	TMatrix<int> m1(size);
	EXPECT_EQ(true, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	int size = 9;
	TMatrix<int> m(size);
	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	int size = 7;
	TMatrix<int> m(size);
	TMatrix<int> m1(size + 1);
	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int size = 2;
	TMatrix<int> tmp(size);
	TMatrix<int> m1(size);
	TMatrix<int> m2(size);
	TMatrix<int> res(size);
	m1[0][0] = 1;
	m1[0][1] = 1;
	m1[1][1] = 1;
	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][1] = 1;
	tmp = m1 + m2;
	res[0][0] = 2;
	res[0][1] = 2;
	res[1][1] = 2;

	EXPECT_EQ(res, tmp);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	int size = 6; 
	int size1 = size + 2;
	TMatrix<int> m1(size);
	TMatrix<int> m2(size1);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int size = 4;
	TMatrix<int> tmp(size);
	TMatrix<int> m1(size);
	TMatrix<int> m2(size);
	TMatrix<int> res(size);
	m1[0][0] = 2;
	m1[0][1] = 2;
	m1[1][1] = 2;
	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][1] = 1;
	tmp = m1 - m2;
	res[0][0] = 1;
	res[0][1] = 1;
	res[1][1] = 1;
	EXPECT_EQ(res, tmp);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int size = 14; 
	int size1 = size + 1;
	TMatrix<int> m1(size);
	TMatrix<int> m2(size1);
	ASSERT_ANY_THROW(m1 - m2);
}