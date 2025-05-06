# include <iostream>
 # include <cstdlib>
 # include <string.h>
 using namespace std;
 struct dt_node
 {
 char caption[ 10];
 int chapters;
 struct dt_node *cnode[10];
 }*root;
 class BOOK
 {
 public:
 void create_tree();
 void display(dt_node *rl);
 BOOK()
 {
 root = NULL;
 }
 };
 void BOOK::create_tree()
 {
 int chp_cnt,i,j,k;
 root = new dt_node();
 cout<<"Enter name of book :";
 cin>>root->caption;
 cout<<"Enter no. of chapters in book :";
 cin>>chp_cnt;
 root->chapters = chp_cnt;
 for(i=0;i<chp_cnt;i++)
 {
 root->cnode[i] = new dt_node;
 cout<<"Enter Chapter name\n ";
 cin>>root->cnode[i]->caption;
 cout<<"Enter no. of sections in Chapter: "<<root->cnode[i]->caption;
 cin>>root->cnode[i]->chapters;
 for(j=0;j<root->cnode[i]->chapters;j++)
 {
 root->cnode[i]->cnode[j] = new dt_node;
 cout<<"\nEnter Section "<<j+1<<"'name\n ";
 cin>>root->cnode[i]->cnode[j]->caption;
 }
 }
 }
 void BOOK::display(dt_node *rl)
 {
 int i,j,k,chp_cnt;
 if(rl != NULL)
 cout<<"\n-----Book Hierarchy--";
 cout<<"\n Book title: "<<rl->caption;
 chp_cnt =rl->chapters;
for(i=0;i<chp_cnt;i++)
 {
 cout<<"\n Chapter: "<<i+1;
 cout<<" "<<rl->cnode[i]->caption;
 cout<<"\n Sections: ";
 for(j=0;j<rl->cnode[i]->chapters;j++)
 {
 cout<<" "<<rl->cnode[i]->cnode[j]->caption;
 }
 }
 }
 int main()
 {
 int choice;
 BOOK BOOK;
 while (1)
 {
 cout<<"\nBook Tree Creation "<<endl;
 cout<<"1.Create"<<endl;
 cout<<"2.Display"<<endl;
 cout<<"3.Quit"<<endl;
 cout<<"Enter your choice :";
 cin>>choice;
 switch(choice)
 {
 case 1:
 BOOK.create_tree();
 case 2:
 BOOK.display(root);
 break;
 case 3:
 exit(1);
 default:
 cout<<"Wrong";
 }
 }
 
