#include "pch.h"﻿
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rut::miit::llist
{
	TEST_CLASS(CircularLinkedList)
	{
	public:
		TEST_METHOD(PrintTest)
		{
			CircularLinkedList list;
			list.CircularLinkedList(1);
			list.append(2);
			list.append(3);
			std::string value = " 1 ";
			
			auto actual = answer.ToString();
			
			Assert::AreEqual(actual, expected);
			auto actual = answer.ToString();
			
			Assert::AreEqual(actual, expected);

		}
	};
}