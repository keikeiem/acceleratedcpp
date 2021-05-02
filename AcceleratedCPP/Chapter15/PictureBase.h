#ifndef PICTURE_BASE_H
#define PICTURE_BASE_H

// ���� Ŭ����
class PictureBase {
	friend class FramePictureBase;
	friend class VCatPictureBase;
	friend class HCatPictureBase;
	friend class StringPictureBase;

	// ���̿� �ʺ�
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	// virtual�� const = 0 ���� �ϸ� ���� ���� �Լ��� ������
	// ���� ���� �Լ��� �ϳ��� ������ Ŭ������ ��ü�μ� ������ �� ����.
	// �̷��� Ŭ������ �߻� �⺻ Ŭ������� �Ѵ�.
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
