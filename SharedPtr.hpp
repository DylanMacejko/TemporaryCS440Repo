#ifndef SharedPtr_HPP
#define SharedPtr_HPP

#include <iostream>
#include <cstdlib>


namespace cs540{
	template <typename T>
	class SharedPtr{
		private:
			T * pointed_val;
			static int num_refs;
		public:
			SharedPtr();
			template <typename U> explicit SharedPtr(U *);
			SharedPtr(const SharedPtr &p);
			template <typename U> SharedPtr(const SharedPtr<U> &p);
			SharedPtr(SharedPtr &&p);
			template <typename U> SharedPtr(SharedPtr<U> &);
			SharedPtr &operator=(const SharedPtr &);
			template <typename U> SharedPtr<T> &operator=(const SharedPtr<U> &);
			SharedPtr &operator=(SharedPtr &&p);
			template <typename U> SharedPtr &operator=(SharedPtr<U> &&p);
			~SharedPtr();

			void reset();
			template <typename U> void reset(U *p);

			T *get() const;
			T &operator*() const;
			T *operator->() const;
			explicit operator bool() const;
	};
}

#endif
