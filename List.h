#ifndef _LIST_QUEUE
#define _LIST_QUEUE


template <typename T>
class DoublyList {

public:		
		DoublyList();
		virtual ~DoublyList();
		virtual void insertHead(T element);
		virtual void insertTail(T element);
		virtual void removeHead();
		virtual void removeTail();
		virtual bool isEmpty();
		virtual void showList();

		class Node {
		
		public:
				T m_value;
				Node* m_next;
				Node* m_prev;

		public:
				T getValue() {
						return this->m_value;
				}

				void setValue(T value) {
						this->m_value = value;
				}

				Node* getNext(){
						return this->m_next;			
				}		
				void setNext(Node* next) {
						this->m_next = next;
				}
				Node* getPrev() {
						return this->m_prev;
				}
				void setPrev(Node* prev) {
						this->m_prev = prev; 
				}
		};		

		virtual Node* getHead() {
				return this->m_head;
		}

private:		
		Node* m_head;
		int m_size;

};

template <typename T>
DoublyList<T>::DoublyList() : m_head(nullptr), m_size(0) {

}

template <typename T>
DoublyList<T>::~DoublyList() {
		Node* tmp = m_head;
		Node* prev;
		while(tmp != nullptr) {
				prev = tmp;
				tmp = tmp->getNext();
				delete prev;
		}
		std::cout << "Destructor is invoked " << std::endl;
}

template <typename T>
void DoublyList<T>::insertHead(T element) {

		Node* node = new Node;
		node->setValue(element);
		node->setNext(m_head);
		node->setPrev(nullptr);

		if( !isEmpty() ) {
				m_head->setPrev(node);
		}
		
		m_head = node;
		++m_size;
}

template <typename T>
void DoublyList<T>::insertTail(T element) {

		if( isEmpty() ) {
				DoublyList<T>::insertHead(element);
				return;
		}

		Node* node = new Node;
		Node* tmp = m_head;

		while(tmp->getNext() != nullptr) {
				tmp = tmp->getNext();
		}

		tmp->setNext(node);
		node->setNext(nullptr);
		node->setValue(element);
		node->setPrev(tmp);

}

template <typename T>
void DoublyList<T>::removeHead() {

		if( isEmpty() ) {
				std::cout << " List is empty can not remove " << std::endl;
				return;
		}

		Node* tmp = m_head;		
		tmp->getNext()->setPrev(nullptr);
		m_head = tmp->getNext();
		delete tmp;
		tmp = nullptr;		
}

template <typename T>
void DoublyList<T>::removeTail() {
		if( isEmpty() ) {
				std::cout << " List is empty can not remove " << std::endl;
				return;
		}
		Node* tmp = m_head;
		while(tmp->getNext() != nullptr) {
				tmp = tmp->getNext();
		}

		tmp->getPrev()->setNext(nullptr);
		delete tmp;
		tmp = nullptr;
}



template <typename T>
void DoublyList<T>::showList() {
		if( isEmpty() ) {
				std::cout << " List is empty can not show" << std::endl;
				return;
		}

		Node* tmp = m_head;
		int ix = 1;
		while(tmp != nullptr) {
				std::cout << ix << "  " << tmp->getValue() << std::endl;
				++ix;
				tmp = tmp->getNext();		
		}
}

template <typename T>
bool DoublyList<T>::isEmpty() {
		return (!m_size) ? true : false;
}		


#endif
