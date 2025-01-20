#pragma once
#include "Object.h"

enum FontExtensionType
{
	OTF,
	TTF,
};

class TextObject : public Object
{
	Text* text;
	Font font;

public:
	FORCEINLINE virtual Text* GetDrawable() const override
	{
		return text;
	}

	FORCEINLINE Font& GetFont()
	{
		return font;
	}

	#pragma region Setter
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		text->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		text->setPosition(_position);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		text->setScale(_scale);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _angle) override
	{
		text->setRotation(_angle);
	}
	FORCEINLINE virtual void SetTransformData(const TransformData& _transformeData) override
	{
		Super::SetTransformData(_transformeData);
		text->setOrigin(_transformeData.origin);
		text->setPosition(_transformeData.position);
		text->setScale(_transformeData.scale);
		text->setRotation(_transformeData.rotation);
	}
	#pragma endregion

	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		text->move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		text->scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		text->rotate(_angle);
	}
public:
	TextObject(const string& _text, const string& _fontPath = "", const FontExtensionType& _fontType = TTF);
	~TextObject();
};

