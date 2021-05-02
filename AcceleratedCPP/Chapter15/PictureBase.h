#ifndef PICTURE_BASE_H
#define PICTURE_BASE_H

// 공통 클래스
class PictureBase {
	friend class FramePictureBase;
	friend class VCatPictureBase;
	friend class HCatPictureBase;
	friend class StringPictureBase;

	// 높이와 너비
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	// virtual에 const = 0 으로 하면 순수 가상 함수로 지정됨
	// 순수 가상 함수를 하나라도 가지는 클래스는 객체로서 존재할 수 없다.
	// 이러한 클래스를 추상 기본 클래스라고 한다.
	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;
public:
	virtual ~PictureBase() {}
};

// StringPicture
class StringPictureBase : public PictureBase {
private:
	std::vector<std::string> data;
	StringPictureBase(const std::vector<std::string>& v) : data(v) {}

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

// FramePicture
class FramePictureBase : public PictureBase {
	Ptr<PictureBase> p;
	FramePictureBase(const Ptr<PictureBase>& pic) : p(pic) {}

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

// HCatPicture
class HCatPictureBase : public PictureBase {
private:
	Ptr<PictureBase> left, right;
	HCatPictureBase(const Ptr<PictureBase>& l, const Ptr<PictureBase>& r) :
		left(l), right(r) {}

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;

};

// VCatPicture
class VCatPictureBase : public PictureBase {
private:
	Ptr<PictureBase> top, bottom;
	VCatPictureBase(const Ptr<PictureBase>& t, const Ptr<PictureBase>& b) :
		top(t), bottom(b) {}

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};



#endif // !PICTURE_BASE_H
