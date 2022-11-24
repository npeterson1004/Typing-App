#ifndef _LINKED_BAG
#define  _LINKED_BAG


#include "Interface.h"
#include "Node.h"

template<class ItemType>
class DoublyLinkedBag : public  BagInterface<ItemType>
{
    private:
        Node<ItemType>*  headPtr;       // Pointer to first node
        int itemCount;                   // Current count of bag items
   
        // Returns either a pointer to the node containing a given entry
        // or the null pointer if the entry is not in the bag.
   
        Node<ItemType>*  getPointerTo(const ItemType& target) const;
   
    public:
        DoublyLinkedBag();
        DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag);//copy contructor
        virtual ~DoublyLinkedBag();
        int getCurrentSize() const;
        bool isEmpty() const;
        bool add(const ItemType& newEntry);
        bool remove(const ItemType& newEntry);
        void clear();
        bool contains(const ItemType&  anEntry) const;
        bool spell_check(const ItemType&  anEntry) const;
        int getFrequencyOf(const ItemType& anEntry) const;
        vector<ItemType> toVector() const;
        bool operator==(const ItemType& newEntry);
        

        
};

    
#include "Linked.cpp"
#endif
        
   