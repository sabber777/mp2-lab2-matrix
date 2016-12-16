#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	int size = 4;
	int SI = 0;
	TVector<int> one(size, SI);
	one[2] = 2;
	TVector<int> two(one);
	EXPECT_EQ(one, two);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	int size = 6; int si = 0;
	TVector<int> tmp(size, si);
	tmp[2] = 4;
	TVector<int> tmp1(tmp);
	tmp1[2] = 6;
	EXPECT_NE(tmp, tmp1);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> tmp;
	ASSERT_ANY_THROW(tmp[-99]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> tmp;
	ASSERT_ANY_THROW(tmp[MAX_VECTOR_SIZE + 1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	int size = 8;  
	int si = 0;
	TVector<int> tmp(size, si);
	ASSERT_NO_THROW(tmp = tmp);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	int size = 4; 
	int si = 0;
	TVector<int> tmp(size, si);
	TVector<int> tmp1(size, si);
	EXPECT_EQ(tmp, tmp1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	int size = 7; 
	int si = 0;  
	int size1 = size + 3;
	TVector<int> tmp(size, si);
	TVector<int> tmp1(size1, si);
	tmp = tmp1;
	EXPECT_EQ(size1, tmp.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	int size = 2; 
	int size1 = 6; 
	int si = 0;
	TVector<int> tmp(size, si);
	TVector<int> tmp1(size1, si);
	tmp = tmp1;
	EXPECT_EQ(tmp, tmp1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	int size = 9; 
	int si = 0;
	TVector<int> one(size, si);
	TVector<int> two(size, si);
	one[1] = 8;
	two[1] = 8;
	EXPECT_EQ(one, two);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	int size = 2; 
	int si = 0;
	TVector<int> tmp(size, si);
	EXPECT_EQ(tmp, tmp);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	int size = 5; 
	int size1 = 8; 
	int si = 0;
	TVector<int> one(size, si);
	TVector<int> two(size1, si);
	EXPECT_NE(one, two);
}

TEST(TVector, can_add_scalar_to_vector)
{
	int val = 4;
	Vector<int> one(1, 0);
	TVector<int> two(1, 0);
	one[0] = 2;
	one[1] = 2;
	one = one + val; 
	two[0] = 4;
	two[1] = 4;
	EXPECT_EQ(one, two);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int val = 1;
	TVector<int> one(2, 0);
	TVector<int> two(2, 0);
	one[0] = 2;
	one[1] = 2;
	one = one - val;
	two[0] = 1;
	two[1] = 1;
	EXPECT_EQ(two, one);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int val = 2;
	TVector<int> one(1, 1);
	TVector<int> two(1, 1);
	one[0] = 3;
	one[1] = 3;
	one = one * val;
	two[0] = 4;
	two[1] = 4;
	EXPECT_EQ(two, one);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int size = 2;
	int si = 0;
	TVector<int> tmp(size, si);
	TVector<int> one(size, si);
	TVector<int> two(size, si);
	TVector<int> three(size, si);
	one[0] = 5;
	one[1] = 5;
	two[0] = 5;
	two[1] = 5;
	three = two + one;
	tmp[0] = 8;
	tmp[1] = 8;
	EXPECT_EQ(tmp, three);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	int size = 3; 
	int size1 = 5;  
	int si = 0;
	TVector<int> one(size, si);
	TVector<int> two(size1, si);
	ASSERT_ANY_THROW(one + two);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int size = 2;  
	int si = 0;
	TVector<int> tmp(size, si);
	TVector<int> one(size, si);
	TVector<int> two(size, si);
	TVector<int> three(size, si);
	one[0] = 4;
	one[1] = 4;
	two[0] = 1;
	two[1] = 1;
	three = one - two;
	tmp[0] = 3;
	tmp[1] = 3;
	EXPECT_EQ(tmp, three);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	int size = 4;
	int size1 = 6;  
	int si = 0;
	TVector<int> one(size, si);
	TVector<int> two(size1, si);
	ASSERT_ANY_THROW(two - one);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int size = 4;  
	int si = 0;
	int tmp;
	int res;
	TVector<int> one(size, si);
	TVector<int> two(size, si);
	one[0] = 3;
	one[1] = 3;
	two[0] = 3;
	two[1] = 3;
	res = two * one;
	tmp = 9;
	EXPECT_EQ(tmp, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int size = 7;  
	int si = 0;
	TVector<int> one(size, si);
	TVector<int> two(size + 1, si);
	ASSERT_ANY_THROW(two*one);
}