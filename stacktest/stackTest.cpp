#include "Mystack.cpp"

#include <gtest.h>

TEST(TStack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, can_get_size)
{
	TStack<int> s(3);
	EXPECT_EQ(3, s.GetSize());
	
}
TEST(TStack, thorws_when_stack_is_full_when_push_elems)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Push(5));
}

TEST(TStack, push_elems_in_empty_stack)
{
	TStack<int> s(5);
	for (int i = 0; i < s.GetSize(); i++) {
		int a = s.GetTop();
	}
	ASSERT_NO_THROW(s.Push(5));
}

TEST(TStack, can_check_is_empty)
{
	TStack<int> s(3);
	EXPECT_EQ(false, s.IsEmpty());

}

TEST(TStack, can_copy_stack_with_equal_size)
{
	TStack<int> s(3);
	TStack<int> s1(3);
	ASSERT_NO_THROW(s = s1);

}

TEST(TStack, can_copy_stack_with_not_equal_size)
{
	TStack<int> s(4);
	TStack<int> s1(3);
	ASSERT_NO_THROW(s = s1);

}

TEST(TStack, can_check_is_full)
{
	TStack<int> s(3);
	EXPECT_EQ(true, s.IsFull());

}

TEST(TStack, get_elems_from_empty_stack)
{
	TStack<int> s(5);
	for (int i = 0; i < s.GetSize(); i++) {
		int a = s.GetTop();
	}
	ASSERT_ANY_THROW(s.GetTop());
}

TEST(TStack, get_elems_from_not_empty_stack)
{
	TStack<int> s(5);

	ASSERT_NO_THROW(s.GetTop());
}
