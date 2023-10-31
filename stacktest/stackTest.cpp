#include "C:\сема\1курс\основы проги\lab stack_queue\all-labs-1-3\stacklib\Mystack.cpp"

#include <gtest.h>

TEST(TStack, throws_when_create_vector_with_negative_size)
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


//TEST(Vector, thorws_when_index_argument_more_or_eq_size) {
//}
//
//TEST(Vector, can_use_index_operator) {
//}
//
//TEST(Vector, can_compare_vectors_true) {
//}
//
//TEST(Vector, can_compare_vectors_false_with_one_size) {
//}
//
//TEST(Vector, can_compare_vectors_false_with_diff_size) {
//}
//
//TEST(Vector, can_assign_vector) {
//}
//
//TEST(Vector, can_prefix_increment) {
//}
//
//TEST(Vector, can_postfix_increment)
//{
//}
//
//TEST(Vector, can_prefix_decrement)
//{
//}
//
//TEST(Vector, can_postfix_decrement)
//{
//}
//
//TEST(Vector, can_unary_addition)
//{
//}
//
//TEST(Vector, can_unary_subtraction)
//{
//}
//
//TEST(Vector, can_addition_vectors)
//{
//}
//
//TEST(Vector, thorws_when_addition_vectors_with_diff_size) 
//{
//}
//
//TEST(Vector, can_subtraction_vectors)
//{
//}
//
//TEST(Vector, thorws_when_subtraction_vectors_with_diff_size)
//{
//}
//
//TEST(Vector, can_multiplication_vectors) 
//{
//}
//
//TEST(Vector, throws_when_multiplication_vectors_with_diff_size)
//{
//}
//
//TEST(Vector, can_multiplication_vector_by_number) 
//{
//}
//
//TEST(Vector, can_multiplication_number_by_vector)
//{
//}