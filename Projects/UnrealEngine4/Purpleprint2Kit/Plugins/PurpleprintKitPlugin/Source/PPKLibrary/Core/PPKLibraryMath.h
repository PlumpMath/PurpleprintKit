/*
===========================================================================
This code is part of the "Source Code" content in
Purpleprint 2 - Kit by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/PurpleprintKit>

The MIT License (MIT)
Copyright (c) 2014-2016 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
PPKLibraryMath.h
================================================
*/


#pragma once

#include <chrono>
#include <random>
#include <math.h>

#include "PPKLibraryMath.generated.h"

UENUM()
enum class EIniFilesList : uint8 {
	GGameIni 				UMETA( DisplayName = "Game" ),
	GGameUserSettingsIni	UMETA( DisplayName = "User Settings" ),
	GScalabilityIni			UMETA( DisplayName = "Scalability" ),
	GInputIni				UMETA( DisplayName = "Input" ),
	GEngineIni				UMETA( DisplayName = "Engine" )
};


UCLASS()
class PPKLIBRARY_API UPPKLibraryMath : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

private:

protected:

public:


	//TODO Random functions

	/** Build the random function seeds */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Random" )
		static void BuildRandom();

	/** Create the random seed */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Random" )
		static void CreateRandomSeed( int32 seed );

	/** Update the random seed */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Random" )
		static void UpdateRandomSeedTime();


	/** Returns a float from two ints A and B to A.B */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Make Float" ), Category = "PP2KLibrary|Math|Float" )
		static float MakeFloatFromInts( const int32 A, int32 B );

	/** Returns split a float into two ints A.B to A and B */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Break Float" ), Category = "PP2KLibrary|Math|Float" )
		static int32 DivideFloatIntoInts( const float Ref, int32 B );

	/** Returns the float inverted A.B to B.A */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Invert Float Order" ), Category = "PP2KLibrary|Math|Float" )
		static float InvertFloat( const float floatValue );

	/** Returns FVector2D(A,B) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D FloatSplitToVector2D( const float FloatValue );

	/** Returns FVector(A,B,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector FloatSplitToVector( const float FloatValue );

	/** Returns FVector4(A,B,0,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 FloatSplitToVector4( const float FloatValue );

	/** Returns FVector2D(A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D VectorToVector2D( const FVector &VectorValue );

	/** Returns FVector2D(A,B) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D Vector4ToVector2D( const FVector4 &Vector4Value );

	/** Returns FVector(A,B,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector Vector2DToVector( const FVector2D &Vector2DValue );

	/** Returns FVector(A,B,C) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector Vector4ToVector( const FVector4 &Vector4Value );

	/** Returns FVector4(A,B,0,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector2DToVector4( const FVector2D &Vector2DValue );

	/** Returns FVector4(A,B,C,0) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 VectorToVector4( const FVector &VectorValue );

	/** Returns the euler like int32 value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "To Full From Half (Integer)" ), Category = "PP2KLibrary|Math|Integer" )
		static int32 IMakeFullFromHalfRot( const int32 intValue );

	/** Returns the euler like float value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "To Full From Half (Float)" ), Category = "PP2KLibrary|Math|Float" )
		static float FMakeFullFromHalfRot( const float floatValue );

	/** Returns the normalize like int32 value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "To Half From Full (Integer)" ), Category = "PP2KLibrary|Math|Integer" )
		static int32 ICMakeHalfFromFullRot( const int32 intValue );

	/** Returns the normalize like float value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "To Half From Full (Float)" ), Category = "PP2KLibrary|Math|Float" )
		static float FMakeHalfFromFullRot( const float floatValue );

	/** Returns the euler like FRotator value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 180 To 360 Rotation" ), Category = "PP2KLibrary|Math|Rotator" )
		static FRotator MakeFullFromHalfRot( const FRotator rotationValue );

	/** Returns the normalize like FRotator value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 360 To 180 Rotation" ), Category = "PP2KLibrary|Math|Rotator" )
		static FRotator MakeHalfFromFullRot( const FRotator rotationValue );


	/** Returns the euler like FVector2D value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 180 To 360 Rotation" ), Category = "PP2KLibrary|Math|Vector2D" )
		static FVector2D V2DMakeFullFromHalfRot( const FVector2D vector2DValue );

	/** Returns the normalize like FVector2D value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 360 To 180 Rotation" ), Category = "PP2KLibrary|Math|Vector2D" )
		static FVector2D V2DMakeHalfFromFullRot( const FVector2D vector2DValue );

	/** Returns the euler like FVector value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 180 To 360 Rotation" ), Category = "PP2KLibrary|Math|Vector" )
		static FVector VMakeFullFromHalfRot( const FVector vectorValue );

	/** Returns the normalize like FVector value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 360 To 180 Rotation" ), Category = "PP2KLibrary|Math|Vector" )
		static FVector VMakeHalfFromFullRot( const FVector vectorValue );

	/** Returns the euler like FVector4 value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 180 To 360 Rotation" ), Category = "PP2KLibrary|Math|Vector4" )
		static FVector4 V4MakeFullFromHalfRot( const FVector4 vector4Value );

	/** Returns the normalize like FVector value */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Convert 360 To 180 Rotation" ), Category = "PP2KLibrary|Math|Vector4" )
		static FVector4 V4MakeHalfFromFullRot( const FVector4 vector4Value );

	/** Returns FRotator(C,B,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderInvert( const FRotator &rotatorValue );

	/** Returns FVector2D(B,A) from the FVector2D(A,B) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector2D" )
		static FVector2D Vector2DOrderInvert( const FVector2D &vector2DValue );

	/** Returns FVector(C,B,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderInvert( const FVector &vectorValue );

	/** Returns FVector4(D,C,B,A) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector4" )
		static FVector4 Vector4OrderInvert( const FVector4 &vector4Value );

	/** Returns FRotator(C,A,B) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderRight( const FRotator &rotatorValue );

	/** Returns FVector(C,A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderRight( const FVector &vectorValue );

	/** Returns FVector(D,A,B,C) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector4OrderRight( const FVector4 &vector4Value );

	/** Returns FRotator(B,C,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderLeft( const FRotator &rotatorValue );

	/** Returns FVector(B,C,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderLeft( const FVector &vectorValue );

	/** Returns FVector(B,C,D,A) from the FVector(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector4OrderLeft( const FVector4 &vector4Value );

	/** Returns the value of the selected bool from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static bool GetConfigBool( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected int32 from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static int32 GetConfigInt( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected float from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static float GetConfigFloat( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FVector from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FVector GetConfigVector( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FRotator from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FRotator GetConfigRotator( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FLinearColor from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FLinearColor GetConfigColor( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FString from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FString GetConfigString( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FVector2D from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FVector2D GetConfigVector2D( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Set the value of the selected bool from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigBool( const FString sectionName, const FString variableName, const bool value, const EIniFilesList iniFile );

	/** Set the value of the selected int32 from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigInt( const FString sectionName, const FString variableName, const int32 value, const EIniFilesList iniFile );

	/** Set the value of the selected float from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigFloat( const FString sectionName, const FString variableName, const float value, const EIniFilesList iniFile );

	/** Set the value of the selected FVector from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigVector( const FString sectionName, const FString variableName, const FVector value, const EIniFilesList iniFile );

	/** Set the value of the selected FRotator from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigRotator( const FString sectionName, const FString variableName, const FRotator value, const EIniFilesList iniFile );

	/** Set the value of the selected FLinearColor from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigColor( const FString sectionName, const FString variableName, const FLinearColor value, const EIniFilesList iniFile );

	/** Set the value of the selected FString from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigString( const FString sectionName, const FString variableName, const FString value, const EIniFilesList iniFile );

	/** Set the value of the selected FVector2D from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigVector2D( const FString sectionName, const FString variableName, const FVector2D value, const EIniFilesList iniFile );

	/** Returns the number of characters in the int */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Integer Size" ), Category = "PP2KLibrary|Math|Utils" )
		static int32 IntCount( const int32 intValue );

	/** Returns the number of characters in the float */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Float Size" ), Category = "PP2KLibrary|Math|Utils" )
		static int32 FloatCount( const float floatValue );

	//Performance problem over here, the Blueprint take about 0.5 to 2min in open.
	//But looks like other location problem no here
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Min (Byte)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Byte" )
		static uint8 BMin( uint8 A, uint8 B );

	/** Returns the maximum value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Max (Byte)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Byte" )
		static uint8 BMax( uint8 A, uint8 B );

	/** Returns the closer value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Closer (Byte)", CompactNodeTitle = "CLOS", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Byte" )
		static uint8 BGetCloser( uint8 Ref, uint8 A, uint8 B );

	/** Returns the further value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Further (Byte)", CompactNodeTitle = "FURT", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Byte" )
		static uint8 BGetFurther( uint8 Ref, uint8 A, uint8 B );

	/** Returns the closer value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Closer (int)", CompactNodeTitle = "CLOS", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Integer" )
		static int32 IGetCloser( int32 Ref, int32 A, int32 B );

	/** Returns the further value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Further (int)", CompactNodeTitle = "FURT", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Integer" )
		static int32 IGetFurther( int32 Ref, int32 A, int32 B );

	/** Returns the closer value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Closer (float)", CompactNodeTitle = "CLOS", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Float" )
		static float FGetCloser( float Ref, float A, float B );

	/** Returns the further value of A and B */
	UFUNCTION( BlueprintPure, meta = ( DisplayName = "Further (float)", CompactNodeTitle = "FURT", CommutativeAssociativeBinaryOperator = "true" ), Category = "PP2KLibrary|Math|Float" )
		static float FGetFurther( float Ref, float A, float B );

	/** Returns the closer integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Integer" )
		static void CloserIntArray( const int32 IntRefValue, const TArray<int32>& IntArray, const bool NotEqual, int32& IndexOfCloserValue, int32& CloserValue );

	/** Returns the further integer in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Integer" )
		static void FurtherIntArray( const int32 IntRefValue, const TArray<int32>& IntArray, int32& IndexOfFurtherValue, int32& FurtherValue );

	/** Returns the closer float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Float" )
		static void CloserFloatArray( const float FloatRefValue, const TArray<float>& FloatArray, const bool NotEqual, int32& IndexOfCloserValue, float& CloserValue );

	/** Returns the further float in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Float" )
		static void FurtherFloatArray( const float FloatRefValue, const TArray<float>& FloatArray, int32& IndexOfFurtherValue, float& FurtherValue );

	/** Returns the closer byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Byte" )
		static void CloserByteArray( const uint8 ByteRefValue, const TArray<uint8>& ByteArray, const bool NotEqual, int32& IndexOfCloserValue, uint8& CloserValue );

	/** Returns the further byte in the array and their index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Byte" )
		static void FurtherByteArray( const uint8 ByteRefValue, const TArray<uint8>& ByteArray, int32& IndexOfFurtherValue, uint8& FurtherValue );

	/** Returns closer value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Closer( const T Reference, const T A, const T B ) {
		return ( ( ( Reference - A ) >= (T)0 ) ? ( Reference - A ) : -( Reference - A ) ) <= ( ( ( Reference - B ) >= (T)0 ) ? ( Reference - B ) : -( Reference - B ) ) ? A : B;
	}

	/** Returns further value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Further( const T Reference, const T A, const T B ) {
		return ( ( ( Reference - A ) >= (T)0 ) ? ( Reference - A ) : -( Reference - A ) ) >= ( ( ( Reference - B ) >= (T)0 ) ? ( Reference - B ) : -( Reference - B ) ) ? A : B;
	}

	/**
	* Closer number to given of Array
	* @param	Array of templated type
	* @param	Reference value templated type to compare
	* @param	Optional boolean to search only the closer values and no the equals
	* @param	Optional pointer for returning the index of the closer element, if multiple closer elements the first index is returned
	* @return	The closer value found in the array or default value if the array was empty or can't find a correct value
	*/
	template< class T >
	static FORCEINLINE T Closer( const T Reference, const TArray<T>& Values, const bool NotEqual, int32* CloserIndex = NULL ) {
		if ( Values.Num() == 0 ) {
			if ( CloserIndex ) {
				*CloserIndex = INDEX_NONE;
			}
			return T();
		}

		T CurCloser = ( ( Reference - Values[0] ) >= (T)0 ) ? ( Reference - Values[0] ) : -( Reference - Values[0] );
		int32 CurCloserIndex = 0;
		if ( CurCloser == 0 && NotEqual ) {
			CurCloserIndex = -1;
		}

		for ( int32 v = 1; v < Values.Num(); ++v ) {
			const T Value = ( ( Reference - Values[v] ) >= (T)0 ) ? ( Reference - Values[v] ) : -( Reference - Values[v] );
			if ( Value < CurCloser ) {
				if ( !NotEqual || ( NotEqual && Value != 0 ) ) {
					CurCloser = Value;
					CurCloserIndex = v;
				}
			}
		}

		if ( CloserIndex ) {
			*CloserIndex = CurCloserIndex == -1 ? INDEX_NONE : CurCloserIndex;
		}
		return Values.Num() == 0 ? 0 : Values[CurCloserIndex == -1 ? 0 : CurCloserIndex];
	}

	/**
	* Further number to given of Array
	* @param	Array of templated type
	* @param	Reference value templated type to compare
	* @param	Optional pointer for returning the index of the further element, if multiple further elements the first index is returned
	* @return	The further value found in the array or default value if the array was empty
	*/
	template< class T >
	static FORCEINLINE T Further( const T Reference, const TArray<T>& Values, int32* FurtherIndex = NULL ) {
		if ( Values.Num() == 0 ) {
			if ( FurtherIndex ) {
				*FurtherIndex = INDEX_NONE;
			}
			return T();
		}

		T CurFurther = ( ( Reference - Values[0] ) >= (T)0 ) ? ( Reference - Values[0] ) : -( Reference - Values[0] );
		int32 CurFurtherIndex = 0;
		for ( int32 v = 1; v < Values.Num(); ++v ) {
			const T Value = ( ( Reference - Values[v] ) >= (T)0 ) ? ( Reference - Values[v] ) : -( Reference - Values[v] );
			if ( CurFurther < Value ) {
				CurFurther = Value;
				CurFurtherIndex = v;
			}
		}

		if ( FurtherIndex ) {
			*FurtherIndex = CurFurtherIndex == -1 ? INDEX_NONE : CurFurtherIndex;
		}
		return Values.Num() == 0 ? 0 : Values[CurFurtherIndex == -1 ? 0 : CurFurtherIndex];
	}

};