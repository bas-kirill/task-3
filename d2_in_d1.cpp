#include "pch.h"
#include "CppUnitTest.h"
#include "../task_2_sem_3/task_2_sem_3.cpp"
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const vec& q) {
				wstringstream s;
				s.precision(4);
				for (auto i = q.begin(); i != q.end(); i++) {
					s << *i << ' ';
				}
				return s.str();
			}
		}
	}
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace d2ind1
{
	TEST_CLASS(d2ind1)
	{
	public:
		
		TEST_METHOD(d2_in_d1_integer)
		{
			vec_2 t_input = { {1,2,3},
							  {4,5,6} 
			};
			vec t_actual = d2_in_d1(t_input,2,3);
			vec t_exprcted = { 1,2,3,4,5,6 };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
		TEST_METHOD(d2_in_d1_double)
		{
			vec_2 t_input = { {1.4,2,3},
							  {4,-5.5,6.7}
			};
			vec t_actual = d2_in_d1(t_input, 2, 3);
			vec t_exprcted = {1.4,2,3.2,4,-5.5,6.7};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
		TEST_METHOD(str)
		{
			vec_2 t_input = { {1,2,4} };
			vec t_actual = d2_in_d1(t_input, 1, 3);
			vec t_exprcted = {1,2,3};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
		TEST_METHOD(d2_in_d1_stolb)
		{
			vec_2 t_input = { {1},{2},{3} };
		
			vec t_actual = d2_in_d1(t_input, 3, 1);
			vec t_exprcted = {1,2,3};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
		
		TEST_METHOD(d2_in_d1_emptyy)
		{
			vec_2 t_input = { {} };
			vec t_actual = d2_in_d1(t_input, 0, 0);
			vec t_exprcted = {};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
		TEST_METHOD(one)
		{
			vec_2 t_input = { {1} };
			vec t_actual = d2_in_d1(t_input, 1, 1);
			vec t_exprcted = {1};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);

		}
	};
}
