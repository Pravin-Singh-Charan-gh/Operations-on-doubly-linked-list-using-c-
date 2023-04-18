#include <iostream>
using namespace std;
class dlinklist
{
private:
    struct dnode {
        dnode *prev;
        int data;
        dnode *next;
    }*head;
public:

    dlinklist()
    {
        head=NULL;
    }

    void d_append(int num)
    {
        dnode *temp=head,*tempoo;

        if(head==NULL) {
            temp=new dnode;
            temp->prev=NULL;
            temp->data=num;
            temp->next=NULL;
            head=temp;
        }

        else {
            while(temp->next!=NULL)
                temp=temp->next;

            tempoo=new dnode;
            tempoo->prev=temp;
            tempoo->data=num;
            tempoo->next=NULL;
            temp->next=tempoo;
        }
    }

    void d_display()
    {
        dnode *temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int d_count()
    {
        int c=0;
        dnode *temp=head;
        while(temp!=NULL) {
            c++;
            temp=temp->next;
        }
        return c;
    }

    void d_delete(int num)
    {
        dnode *temp=head,*tempoo;

        while(temp!=NULL) {
            if(temp->data == num) {


                // 1st node
                if(temp == head) {
                    head=temp->next;
                    temp->next->prev=NULL;
                    delete temp;
                    return;
                }

                // last node
                else if(temp->next == NULL) {
                    temp->prev->next=NULL;
                    delete temp;
                    return;
                }

                // intermediate node
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp=temp->next;
        }
        cout<<"Element "<<num<<" not found.\n";
    }

    void d_addatbeg(int num)
    {
        dnode *temp,*tempoo;
        temp=new dnode;           // for both NULL d.l.l. and existing d.l.l. code will be same.
        temp->data=num;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

    void d_addafter(int loc,int num)
    {
        dnode *temp=head;
        int i;

        for(i=0; i<loc-1; i++) {
            if(temp==NULL) {
                cout<<"There are less number of elements than location "<<loc<<" you entered\n";
                return ;
            }
            temp=temp->next;
        }

        dnode *tempoo=new dnode;
        tempoo->data=num;
        tempoo->prev=temp;
        tempoo->next = temp->next;
        temp->next=tempoo;
        tempoo->next->prev=tempoo;
    }

    ~dlinklist()
    {
        dnode *temp;
        while(head!=NULL) {
            temp=head->next;
            delete head;
            head=temp;
        }
    }
};

int main()
{
    dlinklist dl;
    dl.d_append(1);
    dl.d_append(2);
    dl.d_append(3);
    dl.d_append(4);
    dl.d_append(5);
    dl.d_append(6);
    cout<<"Displaying contents of dll:\n";
    dl.d_display();

    dl.d_addatbeg(23);
    dl.d_addatbeg(99);
    cout<<"D.L.L after adding elments at the beginning:\n";
    dl.d_display();

    dl.d_addafter(9,10);
    dl.d_addafter(1,15);
    dl.d_addafter(1,22);
    cout<<"D.L.L after adding elments in the middle:\n";
    dl.d_display();

    dl.d_delete(4);
    dl.d_delete(12);
    dl.d_delete(15);
    cout<<"D.L.L after deleting elements from the middle:\n";
    dl.d_display();
    return 0;
}
