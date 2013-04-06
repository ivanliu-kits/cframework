#ifndef CFOUNDATION_COLOR_H
#define CFOUNDATION_COLOR_H

#include "cfoundation/Base/Defines.h"
#include "cfoundation/Base/Types.h"
#include "cfoundation/Math/Vector.h"
#include "cfoundation/Text/String.h"

namespace CFoundation
{
    class Serializer;

	class Color
	{
	public:
		Color();
		explicit Color( Unsigned32 u32Color );
		Color( Float16 f16R, Float16 f16G, Float16 f16B, Float16 f16A = 1.0f );
		Color( Unsigned8 u8R, Unsigned8 u8G, Unsigned8 u8B, Unsigned8 u8A = MAX_U8 );
		explicit Color( const Vector3Df &clColor );

        //! Constructor from string
        explicit Color( const String& _sHexString );

        /// Serialization
        void        Serialize( CFoundation::Serializer& _Serializer );

		void        SetU8R( Unsigned8 _u8R );
		void        SetU8G( Unsigned8 _u8G );
		void        SetU8B( Unsigned8 _u8B );
		void        SetU8A( Unsigned8 _u8A );

        void        SetF16R( Float16 _f16R );
        void        SetF16G( Float16 _f16G );
        void        SetF16B( Float16 _f16B );
        void        SetF16A( Float16 _f16A );

		void        SetHex( Unsigned32 u32Color );
		void        SetRGB( Float16 f16R, Float16 f16G, Float16 f16B );
		void        SetRGB( Unsigned8 u8R, Unsigned8 u8G, Unsigned8 u8B );
		void        SetRGBA( Float16 f16R, Float16 f16G, Float16 f16B, Float16 f16A );
		void        SetRGBA( Unsigned8 u8R, Unsigned8 u8G, Unsigned8 u8B, Unsigned8 u8A );

        /// Sets the color from HSV values (H, S and V in interval (0,255))
        void        SetHSV( Unsigned8 _u8H, Unsigned8 _u8S, Unsigned8 _u8V );

		void        ToRGB( Unsigned8& u8R, Unsigned8& u8G, Unsigned8& u8B ) const;
		void        ToRGB( Float16& f16R, Float16& f16G, Float16& f16B ) const;
		void        ToRGBA( Unsigned8& u8R, Unsigned8& u8G, Unsigned8& u8B, Unsigned8& u8A ) const;
		void        ToRGBA( Float16& f16R, Float16& f16G, Float16& f16B, Float16& f16A ) const;
		void        ToHex( Unsigned32 &u32Hex ) const;
		Unsigned32  ToHex() const;

        /// Converts the color to HSV values (H, S and V in interval (0,255))
		void        ToHSV( Unsigned8& _u8H, Unsigned8& _u8S, Unsigned8& _u8V ) const;

		Unsigned8   GetU8R() const;
		Unsigned8   GetU8G() const;
		Unsigned8   GetU8B() const;
		Unsigned8   GetU8A() const;

		Float16     GetF16R() const;
		Float16     GetF16G() const;
		Float16     GetF16B() const;
		Float16     GetF16A() const;

		Unsigned32 GetHex() const;
		const String GetHexString() const;

		bool operator==( const Color& rhs ) const;
		bool operator!=( const Color& rhs ) const;

		Color& operator+=( const Color &rhs );
		Color& operator-=( const Color &rhs );

		Color& operator*=( Float16 d );
		Color& operator*=( const Color &rhs );
		Color& operator*=( const Vector3Df &rhs );

		static Unsigned32 RGBAToHex( Unsigned8 u8R, Unsigned8 u8G, Unsigned8 u8B, Unsigned8 u8A );

		void Mix( const Color &clColor );

	private:
		Unsigned32	m_u32Color;
	};

	Color operator+( const Color &lhs, const Color &rhs );
	Color operator-( const Color &lhs, const Color &rhs );
	Color operator*( const Color &lhs, Float16 d );
	Color operator*( Float16 d, const Color &rhs );
	Color operator*( const Color &lhs, const Color &rhs );
};

#endif