#ifndef Vector3_hpp
#define Vector3_hpp

#include "Mathf.hpp"
#include "FishEngine.hpp"

namespace FishEngine
{

	class FE_EXPORT Vector3
	{
	public:
		union
		{
			struct { float x, y, z; };
			float m[3];
		};

		constexpr static float kEpsilon = 1E-5f;

		Vector3();
		Vector3(float* array);

		// Creates a new vector with given x, y, z components.
		Vector3(float x, float y, float z);

		// Creates a new vector with given x, y components and sets z to zero.
		Vector3(float x, float y);

		float* data();
		const float* data() const;

		float& operator[](const int index);
		float operator[](const int index) const;

		// Returns this vector with a magnitude of 1 (Read Only).
		Vector3 normalized() const;

		// Returns the length of this vector (Read Only).
		float magnitude() const;

		// Returns the squared length of this vector(Read Only).
		float sqrMagnitude() const;

		// Spherically interpolates between two vectors.
		static Vector3 Slerp(const Vector3& a, const Vector3& b, float t);

		// Spherically interpolates between two vectors.
		static Vector3 SlerpUnclamped(const Vector3& a, const Vector3& b, float t);

		// Makes vectors normalized and orthogonal to each other.
		static void OrthoNormalize(Vector3 * normal, Vector3 * tangent);

		// Makes vectors normalized and orthogonal to each other.
		static void OrthoNormalize(Vector3 * normal, Vector3 * tangent, Vector3 * binormal);
		
		// Rotates a vector current towards target.
		static Vector3 RotateTowards(const Vector3& current, const Vector3& target, float maxRadiansDelta, float maxMagnitudeDelta);

		// Linearly interpolates between two vectors.
		// a*(1-t) + b*t
		static Vector3 Lerp(const Vector3& a, const Vector3& b, float t);

		// Linearly interpolates between two vectors.
		// a*(1-t) + b*t
		static Vector3 LerpUnClamped(const Vector3& a, const Vector3& b, float t);

		// Moves a point current in a straight line towards a target point.
		static Vector3 MoveTowards(const Vector3& current, const Vector3& target, float maxDistanceDelta);

		// Gradually changes a vector towards a desired goal over time.
		static Vector3 SmoothDamp(const Vector3& current, const Vector3& target, Vector3& currentVelocity/*ref*/, float smoothTime, float maxSpeed = Mathf::Infinity);

		// Gradually changes a vector towards a desired goal over time.
		static Vector3 SmoothDamp(const Vector3& current, const Vector3& target, Vector3& currentVelocity/*ref*/, float smoothTime, float maxSpeed, float deltaTime);

		// Set x, y and z components of an existing Vector3.
		void Set(float newX, float newY, float newZ);

		// Multiplies two vectors component-wise.
		void Scale(const Vector3& scale);

		// Multiplies every component of this vector by the same component of scale.
		static Vector3 Scale(const Vector3& a, const Vector3& b);

		// Cross Product of two vectors.
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

		

		// Reflects a vector off the plane defined by a normal.
		static Vector3 Reflect(const Vector3& inDirection, const Vector3& inNormal)
		{
			return -2.0f * Vector3::Dot(inNormal, inDirection) * inNormal + inDirection;
		}

		static Vector3 Normalize(const Vector3& value);

		// Makes this vector have a magnitude of 1.
		void Normalize();

		// Dot Product of two vectors.
		static float Dot(const Vector3& lhs, const Vector3& rhs);

		// Projects a vector onto another vector.
		static Vector3 Project(const Vector3& vector, const Vector3& onNormal);

		// Projects a vector onto a plane defined by a normal orthogonal to the plane.
		static Vector3 ProjectOnPlane(const Vector3& vector, const Vector3& planeNormal);

		/**
		 * Returns the angle in degrees between from and to.
		 * 
		 * The angle returned is always the non reflex angle between the two vectors - ie the smaller of the two possible angles between them and never greater than 180 degrees.
		 * 
		 * @param The angle extends round from this vector.
		 * @param The angle extends round to this vector.
		 **/
		static float Angle(const Vector3& from, const Vector3& to);

		// Returns the distance between a and b.
		static float Distance(const Vector3& a, const Vector3& b);

		// Returns the squared distance between a and b.
		static float DistanceSquared(const Vector3& a, const Vector3& b);

		// Returns a copy of vector with its magnitude clamped to maxLength.
		static Vector3 ClampMagnitude(const Vector3& vector, float maxLength);

		static float Magnitude(const Vector3& a);

		static float SqrMagnitude(const Vector3& a);

		// Returns a vector that is made from the smallest components of two vectors.
		static Vector3 Min(const Vector3& lhs, const Vector3& rhs);

		// Returns a vector that is made from the largest components of two vectors.
		static Vector3 Max(const Vector3& lhs, const Vector3& rhs);


		Vector3&    operator=(const Vector3& v);
		Vector3     operator-() const;

		Vector3     operator+(const Vector3& v) const;
		Vector3     operator-(const Vector3& v) const;
		Vector3     operator*(const Vector3& v) const;
		void        operator+=(const Vector3& v);
		void        operator-=(const Vector3& v);
	
		Vector3     operator+(const float f) const;
		Vector3     operator-(const float f) const;
		Vector3     operator*(const float f) const;
		Vector3     operator/(const float f) const;
		void        operator+=(const float f);
		void        operator-=(const float f);
		void        operator*=(const float f);
		void        operator/=(const float f);

		friend Vector3  operator*(const float f, const Vector3& v);
		friend Vector3  operator/(const float f, const Vector3& v);

		friend bool operator==(const Vector3& lhs, const Vector3& rhs)
		{
			return Vector3::SqrMagnitude(lhs - rhs) < 9.99999944E-11f;
		}

		friend bool operator!=(const Vector3& lhs, const Vector3& rhs)
		{
			return Vector3::SqrMagnitude(lhs - rhs) >= 9.99999944E-11f;
		}

		// Returns a nicely formatted string for this vector.
		std::string ToString() const;

	public:

		// Shorthand for writing Vector3(0, 0, 0).
		const static Vector3 zero;

		// Shorthand for writing Vector3(1, 1, 1).
		const static Vector3 one;

		// Shorthand for writing Vector3(0, 0, 1).
		const static Vector3 forward;

		// Shorthand for writing Vector3(0, 0, -1).
		const static Vector3 back;

		// Shorthand for writing Vector3(0, 1, 0).
		const static Vector3 up;

		// Shorthand for writing Vector3(0, -1, 0).
		const static Vector3 down;

		// Shorthand for writing Vector3(-1, 0, 0).
		const static Vector3 left;

		// Shorthand for writing Vector3(1, 0, 0).
		const static Vector3 right;

		

	private:
		bool hasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }
	};


	/************************************************************************/
	/* Implementations                                                      */
	/************************************************************************/

	inline Vector3::Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{
		Assert(!hasNaNs());
	}

	inline Vector3::Vector3(float x, float y)
		: x(x), y(y), z(0)
	{
		Assert(!hasNaNs());
	}

	inline Vector3::Vector3(float* array)
		: x(array[0]), y(array[1]), z(array[2])
	{
	}

	inline Vector3::Vector3()
		: Vector3(0, 0, 0)
	{

	}

	inline const float* Vector3::data() const
	{
		return m;
	}

	inline float* Vector3::data()
	{
		return m;
	}

	inline Vector3 Vector3::normalized() const
	{
		return Vector3::Normalize(*this);
	}

	inline float Vector3::magnitude() const
	{
		return ::std::sqrtf(x*x + y*y + z*z);
	}

	inline float Vector3::sqrMagnitude() const
	{
		return x*x + y*y + z*z;
	}

	inline void Vector3::Set(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}

	inline void Vector3::Scale(const Vector3& scale)
	{
		x *= scale.x;
		y *= scale.y;
		z *= scale.z;
	}

	inline float&      Vector3::operator[](const int index) { return m[index]; }
	inline float       Vector3::operator[](const int index) const { return m[index]; }
	inline Vector3&    Vector3::operator=(const Vector3& v) { Assert(!v.hasNaNs()); x = v.x; y = v.y; z = v.z; return *this; }
	inline Vector3     Vector3::operator-() const { return Vector3(-x, -y, -z); }

	inline Vector3     Vector3::operator+(const Vector3& v) const { Assert(!v.hasNaNs()); return Vector3(x + v.x, y + v.y, z + v.z); }
	inline Vector3     Vector3::operator-(const Vector3& v) const { Assert(!v.hasNaNs()); return Vector3(x - v.x, y - v.y, z - v.z); }
	inline Vector3     Vector3::operator*(const Vector3& v) const { Assert(!v.hasNaNs()); return Vector3(x * v.x, y * v.y, z * v.z); }
	inline void        Vector3::operator+=(const Vector3& v) { Assert(!v.hasNaNs()); x += v.x; y += v.y; z += v.z; }
	inline void        Vector3::operator-=(const Vector3& v) { Assert(!v.hasNaNs()); x -= v.x; y -= v.y; z -= v.z; }

	inline Vector3     Vector3::operator+(const float f) const { Assert(!isnan(f)); return Vector3(x + f, y + f, z + f); }
	inline Vector3     Vector3::operator-(const float f) const { Assert(!isnan(f)); return Vector3(x - f, y - f, z - f); }
	inline Vector3     Vector3::operator*(const float f) const { Assert(!isnan(f)); return Vector3(x * f, y * f, z * f); }
	inline Vector3     Vector3::operator/(const float f) const { Assert(!isnan(f) && f != 0.f); return Vector3(x / f, y / f, z / f); }
	inline void        Vector3::operator+=(const float f) { Assert(!isnan(f)); x += f; y += f; z += f; }
	inline void        Vector3::operator-=(const float f) { Assert(!isnan(f)); x -= f; y -= f; z -= f; }
	inline void        Vector3::operator*=(const float f) { Assert(!isnan(f)); x *= f; y *= f; z *= f; }
	inline void        Vector3::operator/=(const float f) { Assert(!isnan(f)); x /= f; y /= f; z /= f; }

	inline Vector3  operator*(const float f, const Vector3& v) { Assert(!isnan(f) && !v.hasNaNs()); return Vector3(v.x * f, v.y * f, v.z * f); }
	inline Vector3  operator/(const float f, const Vector3& v) { Assert(!isnan(f) && !v.hasNaNs()); return Vector3(f / v.x, f / v.y, f / v.z); }


	inline float Vector3::Angle(const Vector3& from, const Vector3& to)
	{
		return ::std::acosf(Dot(Normalize(from), Normalize(to))) * Mathf::Rad2Deg;
	}

	inline float Vector3::Magnitude(const Vector3& a)
	{
		return ::std::sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	}

	inline float Vector3::SqrMagnitude(const Vector3& a)
	{
		return a.x * a.x + a.y * a.y + a.z * a.z;
	}

	inline Vector3 Vector3::ClampMagnitude(const Vector3& vector, float maxLength)
	{
		if (vector.sqrMagnitude() > maxLength * maxLength)
		{
			return vector.normalized() * maxLength;
		}
		return vector;
	}


	inline float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
	}

	inline Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
	}

	inline float Vector3::Distance(const Vector3& a, const Vector3& b)
	{
		return Magnitude(a - b);
	}

	inline float Vector3::DistanceSquared(const Vector3& a, const Vector3& b)
	{
		return SqrMagnitude(a - b);
	}

	// a*(1-t) + b*t
	inline Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float t)
	{
		t = Mathf::Clamp01(t);
		return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
	}

	// a*(1-t) + b*t
	inline Vector3 Vector3::LerpUnClamped(const Vector3& a, const Vector3& b, float t)
	{
		return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
	}

	inline Vector3 Vector3::Max(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y), std::max(lhs.z, rhs.z));
	}

	inline Vector3 Vector3::Min(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y), std::min(lhs.z, rhs.z));
	}

	inline Vector3 Vector3::Normalize(const Vector3& value)
	{
		float num = value.magnitude();
		if (num > 1E-05f)
		{
			return value / num;
		}
		return Vector3::zero;
	}

	inline void Vector3::Normalize()
	{
		float len = magnitude();
		if (len > 1e-5f) {
			x /= len;
			y /= len;
			z /= len;
		}
		else {
			x = y = z = 0;
		}
	}

	inline Vector3 Vector3::Scale(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x*b.x, a.y*b.y, a.z*b.z);
	}
}

#endif // Vector3_hpp
