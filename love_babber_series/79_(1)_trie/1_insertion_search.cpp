// T.C for insertion and search (O(L))   where L is length of word


#include<iostream>
#include<string>
using namespace std;

class trienode
{
   public:
      // declaration of all the requirments
      char data;
      trienode* children[26];
      bool isterminal;

      // initialization of all the requirments
      trienode(char ch)
      {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal = false;
      }
};

class trie
{
    public:
      // declaring obj pointer
      trienode* root;
      // intializing obj
      trie()
      {
        root= new trienode('\0');     
      }




       
       //  ******************************************************************************************function to insert
      void insertUtil(trienode* root,string word)
      {
        // base case--stopping criteria for recursion
        if(word.length()==0)
        {
            root->isterminal = true;
            return;
        }

        // index of first char in word so that we can start out insertion
        int index = word[0]-'a';
        // declaring upcomig root
        trienode* child;

        // if root already present i.e not null 
        if(root->children[index]!=NULL)
        {  // getting character index to make it root
            child = root->children[index];
        }
        else
        {  // making first char as root of next
            child = new trienode(word[0]);
            root->children[index]=child; // storing it as 
        }

        insertUtil(child,word.substr(1));   // recursive call
       }
       
       // another function to get word
      void insertword(string word)
      {
        insertUtil(root,word);
      }







       //  ******************************************************************************************function to search

      bool searchUtil(trienode* root,string word)
      {
         //base case
         if(word.length()==0)
         {
           return root->isterminal;
         }

         int index = word[0]-'a';
         trienode* child;

         if(root->children[index]!=NULL)
         {
            child = root->children[index];
         }
         else{
            return false;
         }

         return searchUtil(child,word.substr(1));
      }


      bool searchword(string word)
      {
        return searchUtil(root,word);
      }





       //  ******************************************************************************************function to remove
       void removeUtil(trienode* root,string word)
       {
           //base case
           if(word.length()==0)
           {
              root->isterminal = false;

              if(check_child_node_null(root))
              {
                  // if it is checked all its children is null then delete root as it is occupy space,,,,if not null then dekhi kitte root delete krde
                  delete root;
                  root = NULL;
              }
              return;
           }

           int index = word[0]-'a';
           trienode* child=root->children[index];;

           if(child!=NULL)
           {
              removeUtil(child,word.substr(1));

              if(check_child_node_null(root) && !child->isterminal)
              {
                delete root;
                root->children[index] = NULL;
              }
           }
           
           
       }

       bool check_child_node_null(trienode* root)
       {
            for(int i=0;i<26;i++)
            {
              if(root->children[i]!=NULL)
              {
                return false;
              }
            }

            return true;
       }

       void removeword(string word)
       {
           removeUtil(root,word);
       }




       //  ******************************************************************************************function to remove

       bool prefixUtil(trienode* root,string word)
       {
          // same as search only here just when word is completed out of full word return true  
          if(word.length()==0)
          {
             return true;
          }

          int index = word[0]-'a';
          trienode* child;

          if(root->children[index]!=NULL)
          {
            child = root->children[index];
          }
          else{
            return false;
          }

          return prefixUtil(child,word.substr(1));

       }

       bool prefixword(string word)
       {
          return prefixUtil(root,word);
       }

};


int main()
{
    trie *t = new trie();

    t->insertword("tarun");
    t->insertword("taru");
    t->insertword("rohit");
    t->insertword("rohan");
    


    if(t->searchword("rohit"))
    {
      cout<<"word is present in our dictionary"<<endl;
    }
    else{
      cout<<"word is absent in our dictionary"<<endl;
    }



    t->removeword("rohit");




    if(t->searchword("rohit"))
    {
      cout<<"word is present in our dictionary"<<endl;
    }
    else{
      cout<<"word is absent in our dictionary"<<endl;
    }



    if(t->prefixword("tar"))
    {
      cout<<"prefix is present in our dictionary"<<endl;
    }
    else{
      cout<<"prefix is absent in our dictionary"<<endl;
    }

    return 0;

}





