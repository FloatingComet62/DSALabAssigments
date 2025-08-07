#include <iostream>
#include <vector>
#include <optional>

class Data {
  std::optional<std::vector<int>> array;

public:
  Data();
  void create();
  void display();
  void insert();
  void _delete();
  void linearSearch();
};

std::string menu();
bool handle(std::string response, Data& data);

int main() {
  Data data;
  while (true) {
    auto response = menu();
    if (handle(response, data)) break;
  }
  return 0;
}

std::string menu() {
  std::cout
    << "---MENU--" << "\n"
    << "1. CREATE" << "\n"
    << "2. DISPLAY" << "\n"
    << "3. INSERT" << "\n"
    << "4. DELETE" << "\n"
    << "5. LINEAR_SEARCH" << "\n"
    << "6. EXIT" << "\n > ";
  std::string response;
  std::cin >> response;
  for (char& c : response) {
    if (c < 'A' || c > 'Z') continue;
    c += 'a' - 'A';
  }
  return response;
}

bool handle(std::string response, Data& data) {
  if (response == "create") data.create();
  else if (response == "display") data.display();
  else if (response == "insert") data.insert();
  else if (response == "delete") data._delete();
  else if (response == "linear_search") data.linearSearch();
  else if (response == "exit") return true;
  return false;
}

Data::Data() {
  array = std::nullopt;
}
void Data::create() {
  array.emplace();
}
void Data::display() {
  if (!array.has_value()) {
    std::cout << "Array not initialized\n";
    return;
  }
  auto array_value = array.value();
  for (int i = 0; i < array_value.size(); i++) {
    std::cout << array_value[i] << " ";
  }
  std::cout << "\n";
}
void Data::insert() {
  if (!array.has_value()) {
    std::cout << "Array not initialized\n";
    return;
  }

  int num;
  std::cout << "Enter value to insert > ";
  std::cin >> num;

  array->push_back(num);
}
void Data::_delete() {
  if (!array.has_value()) {
    std::cout << "Array not initialized\n";
    return;
  }

  int delete_at;
  while (true) {
    std::cout << "Enter index to delete at > ";
    std::cin >> delete_at;
    if (delete_at >= array->size()) {
      std::cout << "Enter an index within the range\n";
      continue;
    }
    break;
  }

  array->erase(array->begin() + delete_at);
}
void Data::linearSearch() {
  if (!array.has_value()) {
    std::cout << "Array not initialized\n";
    return;
  }

  int num;
  std::cout << "Enter value to find > ";
  std::cin >> num;

  for (int i = 0; i < array->size(); i++) {
    if ((*array)[i] == num) {
      std::cout << "Value found at " << i << "\n";
      return;
    }
  }
  std::cout << "Value not found\n";
  return;
}
