template <class ItemType>
class HashType
{
    public:
    
        HashType();
        // Constructor
        HashType(int s, int factor);
        //Dynamic size constructor
        void MakeEmpty();
        // Function: Returns the list to the empty state.
        // Post: List is empty.
        bool IsFull() const;
        // Function: Determines whether list is full.
        // Pre: List has been initialized.
        // Post: Function value = (list is full)
        int GetNumItems() const;
        // Function: Determines the number of elements in list.
        // Pre: List has been initialized.
        // Post: Function value = number of elements in list
        void RetrieveItem(ItemType& item, bool& found);
        // Function: Retrieves list element whose key matches item's key (if
        // present).
        // Pre: List has been initialized.
        // Key member of item is initialized.
        // Post: If there is an element someItem whose value matches
        // item's value, then found = true and item contains the contents
        // of the item if it is found.
        // otherwise found = false and item is returned unchanged.
        // List is unchanged.
        void InsertItemLinear(ItemType item);
        // Function: Adds item to list and uses a linear probing technique to
        // resolve collisions.
        // Pre: List has been initialized.
        // List is not full.
        // item is not in list.
        // Post: item is in list.
        void InsertItemQuadratic(ItemType item);
        // Function: Adds item to list and uses a quadratic probing technique to
        // resolve collisions.
        // Pre: List has been initialized.
        // List is not full.
        // item is not in list.
        // Post: item is in list.
        void DeleteItem(ItemType item);
        // Function: Deletes the element whose key matches item's key.
        // Pre: List has been initialized.
        // Key member of item is initialized.
        // One and only one element in list has a key matching item's key.
        // Post: No element in list has a key matching item's key.
        int Hash(string item) const;
        //This is the hash function for this class
        unsigned long int GetCollisions() const;
        //return the number of collisions that occured during the build of
        // the hash table
        template <class ItemHash>
        friend ostream& operator<<(ostream& out,
        const HashType<ItemHash>& items);

    private:

        int a; //the value used for a polynomial hash function
        int numItems;
        int size;
        ItemType* info;
        ItemType emptyItem = ""; //The empty string
        unsigned long int numCollisions;
};