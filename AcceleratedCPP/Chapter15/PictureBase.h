#ifndef PICTURE_BASE_H
#define PICTURE_BASE_H

// ���� Ŭ����
class PictureBase {
private:
	// ���̿� �ʺ�
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
	
	// virtual�� const = 0 ���� �ϸ� ���� ���� �Լ��� ������
	// ���� ���� �Լ��� �ϳ��� ������ Ŭ������ ��ü�μ� ������ �� ����.
	// �̷��� Ŭ������ �߻� �⺻ Ŭ������� �Ѵ�.
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
