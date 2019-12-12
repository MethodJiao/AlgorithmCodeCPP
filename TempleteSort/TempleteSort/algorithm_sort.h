#include <vector>

template <class Iterator, class Strategy>
inline void MergeSort(Iterator _First, Iterator _Last,
	Strategy _Strategy)
{
	if (_First == _Last || _Last - _First == 1)
		return;
	typedef iterator_traits<Iterator>::difference_type difference_type;
	difference_type differenceType = (_Last - _First) / 2;
	MergeSort(_First, _First + differenceType, _Strategy);
	MergeSort(_First + differenceType, _Last, _Strategy);
	_merge(_First, _First + differenceType, _First + differenceType, _Last, _Strategy);
}

template <class Iterator, class Strategy>
inline void _merge(Iterator _Part1First, Iterator _Part1Last,
	Iterator _Part2First, Iterator _Part2Last,
	Strategy _Strategy)
{
	Iterator itPart1 = _Part1First;
	Iterator itPart2 = _Part2First;

	typedef iterator_traits<Iterator>::value_type value_type;
	vector<value_type> result;

	while (itPart1 != _Part1Last && itPart2 != _Part2Last){
		if (_Strategy(*itPart1, *itPart2)){
			result.push_back(*itPart1);
			itPart1++;
		}
		else{
			result.push_back(*itPart2);
			itPart2++;
		}
	}

	if (itPart1 < _Part1Last)
		result.insert(result.end(), itPart1, _Part1Last);
	if (itPart2 < _Part2Last)
		result.insert(result.end(), itPart2, _Part2Last);

	itPart1 = _Part1First;
	itPart2 = _Part2First;
	vector<value_type>::iterator it = result.begin();
	while (it != result.end()){
		if (itPart1 != _Part1Last){
			*itPart1 = *it;
			itPart1++;
		}
		else if (itPart2 != _Part2Last){
			*itPart2 = *it;
			itPart2++;
		}
		it++;
	}
}