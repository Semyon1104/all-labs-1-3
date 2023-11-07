#include "Myqueue.cpp"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> s(3));
}
TEST(TQueue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> s(-3));
}

TEST(TQueue, thorws_when_queue_is_full_when_push_elems)
{
	TQueue<int> s(5);
	ASSERT_ANY_THROW(s.Push(5));
}

TEST(TQueue, push_elems_in_empty_queue)
{
	TQueue<int> s(5);
	for (int i = 0; i < 5; i++) {
		int a = s.GetBot_for_tests();
	}
	ASSERT_NO_THROW(s.Push(5));
}

TEST(TQueue, can_check_is_empty)
{
	TQueue<int> s(3);
	EXPECT_EQ(false, s.IsEmpty());

}

TEST(TQueue, get_ind_queue)
{
	TQueue<int> s(2);
	ASSERT_NO_THROW(s.Get());
}

TEST(TQueue, throw_when_get_ind_empty_queue)
{
	TQueue<int> s(1);
	s.GetBot_for_tests();
	ASSERT_ANY_THROW(s.Get());
}

TEST(TQueue, can_check_is_full)
{
	TQueue<int> s(3);
	EXPECT_EQ(true, s.IsFull());

}

TEST(TQueue, get_elems_from_empty_queue)
{
	TQueue<int> s(5);
	for (int i = 0; i < 5; i++) {
		int a = s.GetBot_for_tests();
	}
	ASSERT_ANY_THROW(int a = s.GetBot_for_tests());
}

TEST(TQueue, get_elems_from_not_empty_queue)
{
	TQueue<int> s(5);

	ASSERT_NO_THROW(int a = s.GetBot_for_tests());
}