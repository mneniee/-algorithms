#include <iostream>
#include <cmath>   
#include <vector>
using namespace std;

typedef struct tree_element
{
  string name;
  vector <string> phones;
  struct tree_element* left;
  struct tree_element* right;
  

} tree_element;



tree_element* create(string name, string phone);
tree_element* insert(tree_element* root, string name, string phone);
tree_element* search(tree_element* root, string name);
tree_element* del(tree_element* root, string name);
tree_element* print_tree(tree_element*root, string name);



//Создание
tree_element* create(string name, string phone){
  tree_element* elem = new tree_element;
  elem->name= name;
  elem->phones.push_back(phone);
  elem->left = nullptr;
  elem->right = nullptr;
  return elem;

}


//Добавление элемента
tree_element* insert(tree_element* root, string name, string phone) {
  if(root == nullptr) {
    return create(name, phone);

  }
  if(name < root->name) {
    root->left = insert(root->left, name, phone);


  }
  if(name > root->name) {
    root->right = insert(root->right, name, phone);
  }
  else {
    root->phones.push_back(phone);
  }
  return root;
}




//Поиск 
tree_element* search(tree_element* root, string name) {
  if (root == nullptr || root->name == name) {
        return root;
    }
    if (name < root->name) {
        return search(root->left, name); 
    }
    else {
        return search(root->right, name); 
    }
}



//удаление
tree_element* del(tree_element* root, string name) {
  if (root == nullptr) {
        return root;
    }
    if (name < root->name) {
        root->left = del(root->left, name); 
    }
    else if (name > root->name) {
        root->right = del(root->right, name);
    }
    else {
        if (root->phones.size() > 1) { 
            root->phones.pop_back(); 
        }
        else {
            if (root->left == nullptr) {
                tree_element* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                tree_element* temp = root->left;
                delete root;
                return temp;
            }
            tree_element* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->name = temp->name;
            root->phones = temp->phones;
            root->right = del(root->right, temp->name);
        }
    }
    return root;
}


//Вывод книги
void print(tree_element* root, string name) {
    tree_element* node = search(root, name);
    if (node == nullptr) {
        cout << name << " не найден " << endl;
    }
    else {
        cout << "номера контакта " << name << ": ";
        for (string phone_number : node->phones) {
            cout << phone_number << " ";
        }
        cout << endl;
    }
}

int main() {
  tree_element* root = nullptr;
  string k, k_num, k1, k_num1, m;
    cout << "Введите имя человека № 1: ";
    cin >> k;
    cout << "Введите номер человека № 1: ";
    cin >> k_num;
    cout << "Введите имя человека № 2: ";
    cin >> k1;
    cout << "Введите номер человека № 2: ";
    cin >> k_num1;
    root = insert(root, k, k_num);
    
    root = insert(root, k1, k_num1);
    del(root, k);

  
  
  cout << "Теперь в книге: " << endl;
  print(root, k);
  
  print(root, k1);
  
  cout <<  endl;
  
  
  cout << "Кого хотите удалить ?" << endl;
  cin >> m;
  if(m == k){
    del(root, k);
  }
  else if(m == k1){
    del(root, k1);
  }
  else if(m == "Я не хочу никого удалять") {
    cout << "Вы не хотите никого удалять";
  }
  cout << "После удаления: " << endl;
  print(root, k);
  cout << endl;
  print(root, k1);
  cout << endl;
  return 0;
}
