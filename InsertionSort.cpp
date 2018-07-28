#include <iostream>
#include "List.h"



template <typename T>
void sort(DoublyList<T>& list) {
		typedef typename DoublyList<T>::Node*  node;
		for (node unsorted = list.getHead()->getNext(); unsorted != nullptr; unsorted = unsorted->getNext() ) {         
				T key = unsorted->getValue();                                                              
				node sorted = unsorted->getPrev();     
						

				while( sorted != nullptr && (sorted->getValue() > key)  ) {                                 

						sorted->getNext()->setValue( sorted->getValue() );                                          
						sorted = sorted->getPrev();                                                        

				}                                                                                     

				if(sorted == nullptr) {                                                               
						list.getHead()->setValue(key);						
				} else {                                                                              
						sorted->getNext()->setValue(key);                                                        
				}                                                                                     
		}                                                                                             
}              


int main() {
		DoublyList<int> list;
		list.insertHead(5);
		list.insertHead(235);
		list.insertTail(9);
		list.insertTail(-9);
		list.insertHead(999);
		list.removeHead();
		list.showList();

		sort(list);
		std::cout << "List after insertion Sort  " << std::endl;
		list.showList();
}
