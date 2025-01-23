#pragma once
#include <vector>
#include <stdint.h>

class SortAlgs
{
	static void RevisedBubbleSort(std::vector<uint8_t> data);
	static void SelectionSort(std::vector<uint8_t> data);
	static void InsertionSort(std::vector<uint8_t> data);
	static void QuickSort(std::vector<uint8_t> data);
	static void MergeSort(std::vector<uint8_t> data);
};

