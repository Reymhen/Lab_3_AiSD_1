#include "pch.h"
#include "CppUnitTest.h"
#include "../Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3AiSD
{
	TEST_CLASS(UnitTestLab3AiSD)
	{
	public:
		TEST_METHOD(ContainsTest)
		{
			Tree test_tree;
			test_tree.insert(20);
			test_tree.insert(3);
			test_tree.insert(0);
			test_tree.insert(-1);

			Assert::IsTrue(test_tree.contains(-1));
			Assert::IsTrue(test_tree.contains(0));
			Assert::IsTrue(test_tree.contains(20));
			Assert::IsTrue(test_tree.contains(3));
			Assert::IsTrue(!test_tree.contains(1));
			Assert::IsTrue(!test_tree.contains(10));
		}
		TEST_METHOD(InsertTest) {
			Tree test_tree;
			test_tree.insert(20);
			test_tree.insert(22);
			test_tree.insert(0);
			test_tree.insert(5);
			test_tree.insert(-1);


			Iterator* bft_iterator = test_tree.create_bft_iterator();
			Assert::IsTrue(bft_iterator->next() == 20);
			int next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 0 || next_value == 20);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 0 || next_value == 22);
			Assert::IsTrue(next_value >= bft_iterator->next());
		}
		TEST_METHOD(RemoveTest) {
			Tree test_tree;
			test_tree.insert(20);
			test_tree.insert(0);
			test_tree.insert(-11);

			Assert::IsTrue(test_tree.contains(-11));
			Assert::IsTrue(test_tree.contains(0));
			Assert::IsTrue(test_tree.contains(20));

			test_tree.remove(-11);
			Assert::IsTrue(!test_tree.contains(-11));
			Assert::IsTrue(test_tree.contains(0));
			Assert::IsTrue(test_tree.contains(20));

			test_tree.remove(0);
			Assert::IsTrue(!test_tree.contains(-11));
			Assert::IsTrue(!test_tree.contains(0));
			Assert::IsTrue(test_tree.contains(20));

			test_tree.remove(20);
			Assert::IsTrue(!test_tree.contains(-11));
			Assert::IsTrue(!test_tree.contains(0));
			Assert::IsTrue(!test_tree.contains(20));

		}
		TEST_METHOD(CreateBftIteratorTest) {
			Tree test_tree;

			test_tree.insert(5);
			test_tree.insert(4);
			test_tree.insert(3);
			test_tree.insert(2);
			test_tree.insert(1);
			test_tree.insert(0);

			Iterator* bft_iterator = test_tree.create_bft_iterator();

			int i = 5;
			while (bft_iterator->has_next()) {
				Assert::IsTrue(bft_iterator->next() == i--);
			}
			Assert::IsTrue(i == -1);
		}
		TEST_METHOD(CreateDftIteratorTest) {
			Tree test_tree;

			test_tree.insert(5);
			test_tree.insert(4);
			test_tree.insert(3);
			test_tree.insert(2);
			test_tree.insert(6);
			test_tree.insert(0);

			Iterator* dft_iterator = test_tree.create_dft_iterator();
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 5);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 4);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 3);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 2);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 0);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 6);
			Assert::IsTrue(!dft_iterator->has_next());

		}
		TEST_METHOD(NextTest) {
			Tree test_tree;
			test_tree.insert(5);
			test_tree.insert(4);
			test_tree.insert(3);
			test_tree.insert(2);
			test_tree.insert(6);
			test_tree.insert(0);
			Iterator* iter = test_tree.create_dft_iterator();
			try {
				for (int i = 0; i < 10; i++) {
					iter->next();
				}
			}
			catch (std::out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}

		}
	};
}
