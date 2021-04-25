#ifndef PICTURE_BASE_H
#define PICTURE_BASE_H

// 공통 클래스
class PictureBase {
private:
	// 높이와 너비
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	// virtual에 const = 0 으로 하면 순수 가상 함수로 지정됨
	// 순수 가상 함수를 하나라도 가지는 클래스는 객체로서 존재할 수 없다.
	// 이러한 클래스를 추상 기본 클래스라고 한다.
	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;
};

// StringPicture
class StringPictureBase : public PictureBase {
public:
	StringPictureBase();
	~StringPictureBase();
private:

};

// FramePicture
class FramePictureBase : public PictureBase {
public:
	FramePictureBase();
	~FramePictureBase();
private:

};

// HCatPicture
class HCatPictureBase : public PictureBase {
public:
	HCatPictureBase();
	~HCatPictureBase();
private:

};

// VCatPicture
class VCatPictureBase : public PictureBase {
public:
	VCatPictureBase();
	~VCatPictureBase();
private:

};



#endif // !PICTURE_BASE_H
