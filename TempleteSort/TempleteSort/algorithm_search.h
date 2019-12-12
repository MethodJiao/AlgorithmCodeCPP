
template<class Iterator, class Strategy, class T>
Iterator BinarySearch(Iterator _First, Iterator _Last, Strategy _Strategy, const T& key)
{
	Iterator first = _First;
	Iterator end = _Last - 1;
	Iterator mid;
	while (first <= end)
	{
		mid = first + distance(first, end) / 2;
		if (_Strategy(*mid, key) > 0)
			end = mid - 1;
		else if (_Strategy(*mid, key) < 0)
			first = mid + 1;
		else
			return mid;
	}
	return _Last;
}