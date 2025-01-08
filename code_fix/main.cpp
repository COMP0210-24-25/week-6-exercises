#include <iostream>
#include <exception>

/**
 * @brief A class for holding 2D arrays of integer data.
 */
class Array2D
{
public:
  Array2D(int n_rows_in, int n_cols_in)
      : n_rows(n_rows_in), n_cols(n_cols_in), total_size(n_rows_in * n_cols_in), data(nullptr)
  {
    data = new int[total_size];
    initialise();
  }

  ~Array2D()
  {
    // Make sure to clean up memory!
    delete[] data;
  }

  /**
   * @brief Initialise data to 0
   */
  void initialise()
  {
    for (int i = 0; i < total_size; ++i)
    {
      data[i] = 0;
    }
  }

  /**
   * @brief Get value at indices (i,j)
   *
   * @param i row index
   * @param j column index
   * @return int& reference to integer value
   */
  int &get(int i, int j)
  {

    int idx = i * n_cols + j;
    return data[idx];
  }

  /**
   * @brief Increment all elements by 1
   */
  void increment()
  {
    for (int i = 0; i < total_size; ++i)
    {
      data[i] += 1;
    }
  }

  /**
   * @brief Check whether a value is present in an Array2D
   *
   * @param val
   * @return true if there is an element equal to val
   * @return false otherwise
   */
  bool find(int val)
  {
    for (int i = 0; i < total_size; i++)
    {
      if (data[i] == val)
      {
        return true;
      }
    }
    return false;
  }

  /**
   * @brief Print to stdout
   */
  void print()
  {
    for (int i = 0; i < n_rows; ++i)
    {
      for (int j = 0; j < n_cols; ++j)
      {
        std::cout << get(i, j);
      }
      std::cout << std::endl;
    }
  }

  /**
   * @brief Check if Array2D is square
   *
   * @return true if n_cols and n_rows are equal
   * @return false otherwise
   */
  bool is_square()
  {
    return n_cols == n_rows;
  }

  /**
   * @brief Change size of Array2D.
   * All data from previous array which will fit is copied into the new array.
   * Any remaining elements (if the new size is larger) are initialised to 0.
   *
   * @param n_rows_in New number of rows
   * @param n_cols_in New number of columns
   */
  void change_size(int n_rows_in, int n_cols_in)
  {
    int total_size_new = n_rows_in * n_cols_in;
    // Create new data
    auto data_new = new int[total_size_new];
    // Copy old data
    for (int i = 0; i < total_size_new; ++i)
    {
      if (i < total_size)
      {
        data_new[i] = data[i];
      }
      else
      {
        data_new[i] = 0;
      }
    }
    // clean up old data
    delete[] data;

    // Assign data pointer to the newly allocated array
    data = data_new;
    total_size = total_size_new;
    n_rows = n_rows_in;
    n_cols = n_cols_in;
  }

private:
  int n_rows;
  int n_cols;
  int total_size;
  int *data;
};

Array2D makeSquareArray(int n_rows)
{
  Array2D arr(n_rows, n_rows);
  return arr;
}

void test(bool test_value, const std::string msg = "")
{
  std::cout << msg << ": " << (test_value ? "Pass" : "Fail") << std::endl;
}

int main()
{
  Array2D arr(10, 5);

  std::cout << "Testing increment" << std::endl;
  test(arr.get(1, 2) == 0);
  arr.increment();
  test(arr.get(1, 2) == 1);

  std::cout << "Testing printing" << std::endl;
  arr.print();
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Testing changing size" << std::endl;
  arr.change_size(5, 5);
  test(arr.get(1, 2) == 1);
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Testing finding value" << std::endl;
  test(arr.find(4) == false);
  arr.get(4, 3) = 4;
  test(arr.get(4, 3) == 4);
  test(arr.find(4) == true);

  Array2D squareArray2D = makeSquareArray(5);
  squareArray2D.print();

  return 0;
}
