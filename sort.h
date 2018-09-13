#pragma once
namespace algorithm
{
#define TEMPLATE(T) template<typename T>
#define COUNTOF(array) (sizeof(array)/sizeof(array[0]))

	template<typename T>
	void Swap(T * A, int i, int j)
	{
		T t = A[i];
		A[i] = A[j];
		A[j] = t;
	}

	template<typename T>
	void Swap(T& A, T& B)
	{
		T t = A;
		A = B;
		B = t;
	}

	template<typename T>
	void BubbleSort(T * A, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (A[j] > A[j + 1])
					Swap(A, j, j + 1);
			}
		}
	}

	template<typename T>
	void CockSort(T * A, int n)
	{
		int L = 0, R = n - 1;
		while (L < R)
		{
			for (int i = 0; i < R; i++)
			{
				if (A[i] > A[i + 1])
					Swap(A, i, i + 1);
			}
			R--;
			for (int i = R; i > L; i--)
			{
				if (A[i] < A[i - 1])
					Swap(A, i, i - 1);
			}
			L++;
		}
	}

	template<typename T>
	void SelectionSort(T * A, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < n; j++)
			{
				if (A[j] < A[min])
					min = j;
			}
			if (min != i)
				Swap(A, i, min);
		}
	}

	template<typename T>
	void InsertionSort(T * A, int n)
	{
		for (int i = 1; i < n; i++)
		{
			T t = A[i];
			int j = i - 1;
			while (j >= 0 && A[j] > t)
			{
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = t;
		}
	}

	template<typename T>
	void InsertionSort2(T * A, int n)
	{
		for (int i = 1; i < n; i++)
		{
			T t = A[i];
			int L = 0, R = i - 1;
			while (L <= R)
			{
				int mid = (L + R) / 2;
				if (A[mid] > t)
					R = mid - 1;
				else
					L = mid + 1;
			}
			for (int j = i - 1; j >= L; j--)
			{
				A[j + 1] = A[j];
			}
			A[L] = t;
		}
	}

	template<typename T>
	void ShellSort(T * A, int n)
	{
		int h = 0;
		while (h < n)
		{
			h = 3 * h + 1;
		}

		while (h >= 1)
		{
			for (int i = h; i < n; i++)
			{
				int j = i - h;
				T t = A[i];
				while (j >= 0 && A[j] > t)
				{
					A[j + h] = A[j];
					j -= h;
				}
				A[j + h] = t;
			}
			h = (h - 1) / 3;
		}
	}

	template<typename T>
	void Merge(T * A, int l, int m, int r)
	{
		int n = r - l + 1;
		T * temp = new T[n];
		int index = 0, i = l, j = m + 1;
		while (i <= m && j <= r)
		{
			temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
		}
		while (i <= m)
		{
			temp[index++] = A[i++];
		}
		while (j <= r)
		{
			temp[index++] = A[j++];
		}
		for (index = 0; index < n; index++)
		{
			A[l++] = temp[index];
		}
		delete[] temp;
	}

	template<typename T>
	void MergeSort(T * A, int n)
	{
		int l, m, r;
		for (int i = 1; i < n; i *= 2)
		{
			l = 0;
			while (l + i < n)
			{
				m = l + i - 1;
				r = m + i < n ? m + i : n - 1;
				Merge(A, l, m, r);
				l = r + 1;
			}
		}
	}

	template<typename T>
	void MergeSort(T * A, int l, int r)
	{
		if (l >= r)
			return;

		int m = (l + r) / 2;
		MergeSort(A, l, m);
		MergeSort(A, m + 1, r);
		Merge(A, l, m, r);
	}

	template<typename T>
	int Partition(T * A, int l, int r)
	{
		T pivot = A[r];
		for (int i = l; i < r; i++)
		{
			if (A[i] <= pivot)
			{
				Swap(A, l++, i);
			}
		}
		Swap(A, l, r);
		return l;
	}

	template<typename T>
	void QuickSort(T * A, int n)
	{
		if (n <= 0)
			return;

		int iPivot = Partition(A, 0, n - 1);
		QuickSort(A, iPivot);
		QuickSort(&A[iPivot + 1], n - iPivot - 1);
	}
}
