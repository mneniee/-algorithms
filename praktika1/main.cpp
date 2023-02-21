#include <iostream>
#include <cmath>   

using namespace std;

typedef struct tree_element
{
  int value;
  struct tree_element* left;
  struct tree_element* right;
  

} tree_element;

tree_element* create_element(int i) ;
void insert_in_tree(tree_element* root, tree_element* elem);
void print_tree(tree_element* cur_elem);
void print_tree_1(tree_element* cur_elem);
int hight_tree(tree_element* root);
bool searh(tree_element* root, int search_elem);
void delete_elem(tree_element* root, tree_element* elem);



//Создание


tree_element* create_element(int i) {
  tree_element* elem = new tree_element;
  elem->value = i;
  elem->left = NULL;
  elem->right = NULL;
  return elem;
}



//Вставка
void insert_in_tree(tree_element* root, tree_element* elem) {
  if(elem->value < root->value) {
    if(root->left == NULL){
      root->left = elem;
    } else {
      insert_in_tree(root->left, elem);
    }
  } else {
    if(root->right == NULL){
      root->right = elem;
    } else {
      insert_in_tree(root->right, elem);
    }
  }
}

//Вывод обычный

void print_tree(tree_element* cur_elem) {
  if(cur_elem ->left != NULL){
    print_tree(cur_elem->left);
  }


  cout<< "Значение = " << cur_elem->value << endl; //root


  if(cur_elem ->right != NULL){
    print_tree(cur_elem->right);
  } 

}


//Вывод обход
void print_tree_1(tree_element* cur_elem){
  if(cur_elem ->right != NULL){
    print_tree_1(cur_elem->right);
  }
  cout << "Значение = " << cur_elem->value << endl;
  if(cur_elem ->left != NULL){
    print_tree_1(cur_elem->left);
  }
}


// Глубина

int hight_tree(tree_element* root) {
  if(root == nullptr){
    return 0;
  }

  int k_l = hight_tree(root->left);
  int k_r = hight_tree(root->right);

  if(root->left == nullptr) {
    return k_r + 1;
  }
  if(root->right == nullptr) {
    return k_l + 1;
  }
  return max(k_l, k_r) + 1;
}

//Поиск

void search(int search_elem, tree_element *root){
    if(root == nullptr){
        return;
    }
    if(root->value== search_elem){
        cout << "Найден" << endl;
        
    }
    else {
      cout <<"Не найден" << endl;
    }
    search(search_elem, root->left);
    search(search_elem, root->right);
    
    
}

//Удаление узла


struct tree_element* delete_elem(tree_element* root, int value) {
  if(root == NULL) {
    return root;
  }
  if(value < root->value) {
    root->left = delete_elem(root->left, value);
  }
  else if(value > root->value) {
    root->right = delete_elem(root->right, value);
  }
  else {
    if(root->left == NULL) {
      struct tree_element* elem = root->right;
      free(root);
      return elem;
    }
    else if(root->right == NULL) {
      struct tree_element* elem = root->left;
      free(root);
      return elem;
    }

  }
  return root;

  

}




int main() {
  int k, kolvo, r, s;
  /*int a[6] = {2, 5, 7, -3, -4, -23};
  tree_element* root = create_element(1);
  for (int i = 0; i < 6; i ++) {
    tree_element* el = create_element(a[i]);
    insert_in_tree(root, el);
    
  }
  */
  
  //cout << "Заполним дерево: ";
  
  int a[9] = {};
  cout << "Создайте корень: ";
  cin >> r;
  tree_element* root = create_element(r);
  cout << endl;
  for(int i = 0; i < 9; i ++) {
    a[i] = rand() % 20;
    tree_element* el = create_element(a[i]);
    insert_in_tree(root, el);

  }


  cout << "Дерево >><<>><< " << endl ;
  print_tree(root);
  cout << "Дерево (обход) >><<>><< " << endl;
  print_tree_1(root);
  cout << "Глубина: " << hight_tree(root) << endl;
  cout << "Введите элемент дерева для поиска" << endl;
  cin >> k;
  search(k, root);
  cout << endl;
  
  cout << "Введите элемент дерева для удаления" << endl;
  cin >> k;
  cout << "После удаления" << endl;
  root = delete_elem(root, k);
  print_tree(root);
  
  return 0;

}
