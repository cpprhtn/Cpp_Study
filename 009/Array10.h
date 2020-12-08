#define MAX 10

class Array10{
public:
    void set_arr(int*);
    void reverse();
    int get(int);
private:
    int arr[MAX];
    void swap(int&, int&);
};