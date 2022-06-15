#pragma once

#include <math.h>
#include "precision.h"

// TODO understand this fully before moving beyond particle code!!!

namespace typhoon {
	/*
	 * A vector in 3 dimensions.
	 *
	 * There are several inlines for basic math operations on vectors.
	 */
	class Vector3 {
		/*
		 * Data.
		 */
		public :
			// three cartesian components of the 3-vector
			real x;
			real y;
			real z;
		private :
			// padding to improve storage efficiency
			real pad;

		/*
		 * Methods.
		 */
		public :
			/*
			 * Constructors
			 */

			Vector3() : x(0), y(0), z(0) {}
			Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}


			/*
			 * Vector math operations.
			 */

			void invert() {
				x = -x;
				y = -y;
				z = -z;
			}

			real magnitude() const {
				return sqrt(x*x + y*y + z*z);
			}

			real squareMagnitude() const {
				return x*x + y*y + z*z;
			}

			void normalize() {
				real l = magnitude();
				if (l > 0) {
					(*this) *= ((real) 1)/l;
				}
			}


			/*
			 * Scalar multiplication (handled by overloaded operators).
			 */

			void operator*=(const real c) {
				x *= c;
				y *= c;
				z *= c;
			}

			Vector3 operator*(const real c) const {
				return Vector3(c*x, c*y, c*z);
			}


			/*
			 * Vector addition and subtraction (handled by overloaded
			 * operators).
			 */

			void operator+=(const Vector3& v) {
				x += v.x;
				y += v.y;
				z += v.z;
			}

			Vector3 operator+(const Vector3& v) const {
				return Vector3(x + v.x, y + v.y, z + v.z);
			}

			void operator-=(const Vector3& v) {
				x -= v.x;
				y -= v.y;
				z -= v.z;
			}

			Vector3 operator-(const Vector3& v) const {
				return Vector3(x - v.x, y - v.y, z - v.z);
			}

			void addScaledVector(const Vector3& v, real c) {
				x += c*v.x;
				y += c*v.y;
				z += c*v.z;
			}


			/*
			 * Vector multiplication.
			 */

			/*
			 * Component-wise multiplication. This is not super useful,
			 * so we won't overload any operator to handle this
			 * operation.
			 */ 

			Vector3 componentProduct(const Vector3& v) const {
				return Vector3(x*v.x, y*v.y, z*v.z);
			}

			void componentProductUpdate(const Vector3& v) {
				x *= v.x;
				y *= v.y;
				z *= v.z;
			}


			/*
			 * Dot product.
			 */

			real scalarProduct(const Vector3& v) const {
				return x*v.x + y*v.y + z*v.z;
			}

			real operator*(const Vector3& v) const {
				return x*v.x + y*v.y + z*v.z;
			}


			/*
			 * Cross product.
			 */

			Vector3 vectorProduct(const Vector3& v) const {
				return Vector3(y*v.z - z*v.y,
					       z*v.x - x*v.z,
					       x*v.y - y*v.x);
			}

			Vector3 operator%(const Vector3& v) const {
				return Vector3(y*v.z - z*v.y,
					       z*v.x - x*v.z,
					       x*v.y - y*v.x);
			}

			void operator%=(const Vector3& v) {
				*this = vectorProduct(v);
			}
	};


	/*
	 * Scalar multiplication of a vector is commutative.
	 * TODO figure out how to do this within class definition, or learn how to
	 * use friend functions.
	 */

	inline Vector3 operator*(const real c, const Vector3& v) {
		return v*c;
	}
}
