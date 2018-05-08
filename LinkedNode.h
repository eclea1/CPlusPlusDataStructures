using namespace std;

template <typename T> class LinkedNode {
    public:
        LinkedNode<T>* previous;
        LinkedNode<T>* next;
        void setData(T);
        T getData();
        void setNext(LinkedNode<T>* next);
        void setPrevious(LinkedNode<T>* previous);
        LinkedNode(T data);
        LinkedNode(T data, LinkedNode<T>* next, LinkedNode<T>* previous);
        bool operator== (const LinkedNode<T>& other);
    private:
        T data;

};

/*
Basic Linked Node Constructor for NULL next and previous
Parameter:
    T data - data to be held in the node
*/
template<typename T>
LinkedNode<T>::LinkedNode(T data) {
    this->data = data;
    this->next = NULL;
    this->previous = NULL;
}

/*
Basic Linked Node Constructor to also set next and previous
Parameter:
    T data - data to be held in the node
    LinkedNode<T>* next - next node in the link
    LinkedNode<T>* previous - previous node in the link
*/
template <typename T>
LinkedNode<T>::LinkedNode(T data, LinkedNode<T>* next, LinkedNode<T>* previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
}

/*
Set the next node
Parameter:
    LinkedNode*<T> next - the next node in the list
*/
template <typename T>
void LinkedNode<T>::setNext(LinkedNode<T>* next) {
    this->next = next;
}

/*
Set the previous node
Parameter:
    LinkedNode*<T> previous - the previous node in the list
*/
template <typename T>
void LinkedNode<T>::setPrevious(LinkedNode* previous) {
    this->previous = previous;
}

/*
Get the data in this node
Returns data of type T
*/
template <typename T>
T LinkedNode<T>::getData() {
    return data;
}

/*
Set the data in this node
Parameter:
    T data - data for this node
*/
template <typename T>
void LinkedNode<T>::setData(T data) {
    this.data = data;
}

/*
Override the == operator
*/
template <typename T>
bool LinkedNode<T>::operator==(const LinkedNode<T>& other) {
    if (data != other.data) {
        return false;
    }
    if (next == other.next && previous == other.previous) {
        return true;
    }
    return false;
}