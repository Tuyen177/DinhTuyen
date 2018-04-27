#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
struct Sinhvien
{
	wchar_t MSSV[11];
	wchar_t Ten[31];
	wchar_t Khoa[31];
	wchar_t KhoaHoc[10];
	wchar_t Nam[11];
	wchar_t Email[30];
	wchar_t Hinhanh[16];
	wchar_t Motabanthan[30];
	wchar_t Sothich1[30];
	wchar_t Sothich2[30];
};
struct Sinhvien SV[256];
void Chuyen(wchar_t *b, wchar_t a[])
{
	for (int i = 0; i <= wcslen(b); i++)
		a[i] = b[i];
}
void DocFile(wchar_t *a)
{

	int i = 0;
	wchar_t *p;
	wchar_t **b = (wchar_t **)malloc(8 * sizeof(wchar_t));

	p = wcstok(a, L"\",");
	while (p != NULL)
	{
		b[i] = p;
		i++;
		p = wcstok(NULL, L"\",");
	}

	Chuyen(b[0], SV->MSSV);
	Chuyen(b[1], SV->Ten);
	Chuyen(b[2], SV->Khoa);
	Chuyen(b[3], SV->KhoaHoc);
	Chuyen(b[4], SV->Nam);
	Chuyen(b[5], SV->Email);
	Chuyen(b[6], SV->Hinhanh);
	Chuyen(b[7], SV->Motabanthan);
	Chuyen(b[8], SV->Sothich1);
	Chuyen(b[9], SV->Sothich2);

}
void Vietfile(wchar_t *a)
{
	wchar_t filename[30];
	wcscpy(filename, SV->MSSV);
	wcscat(filename, L".html");
	FILE* fo = _wfopen(filename, L"wt");
	_setmode(_fileno(fo), _O_U8TEXT);
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(fo, L"		<title>HCMUS - %ls</title>\n", SV->MSSV);
	fwprintf(fo, L"	</head>\n");
	fwprintf(fo, L"	<body>\n");
	fwprintf(fo, L"		<div class=\"Layout_container\">\n");
	fwprintf(fo, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(fo, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(fo, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(fo, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(fo, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(fo, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(fo, L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fo, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(fo, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", SV->Ten, SV->MSSV);
	fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<div class=\"Personal_Phone\">\n");
	fwprintf(fo, L"                        Email: %ls </li>\n", SV->Email);
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", SV->Hinhanh);
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"				<!-- End Below Banner Region -->\n");
	fwprintf(fo, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(fo, L"				<div class=\"MainContain\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					<!-- Begin Top Region -->\n");
	fwprintf(fo, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n", SV->Ten);
	fwprintf(fo, L"								 <li>MSSV: %ls </li>\n", SV->MSSV);
	fwprintf(fo, L"								 <li>Sinh viên khoa %ls </li>\n", SV->Khoa);
	fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n", SV->Nam);
	fwprintf(fo, L"								 <li>Email: %ls </li>\n", SV->Email);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>%ls</li>\n", SV->Sothich1);
	fwprintf(fo, L"								 <li>%ls</li>\n", SV->Sothich2);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fo, L"						<div class=\"Description\">\n");
	fwprintf(fo, L"                            %ls.\n", SV->Motabanthan);
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(fo, L"				<div class=\"divCopyright\">\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"				@2018</br>\n");
	fwprintf(fo, L"				Đồ án giữa kì</br>\n");
	fwprintf(fo, L"				Kỹ thuật lâp trình</br>\n");
	fwprintf(fo, L"				TH2018/04</br>\n");
	fwprintf(fo, L"				1712888 - Nguyễn Đình Tuyên</br>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Footer -->\n");
	fwprintf(fo, L"		</div>\n");
	fwprintf(fo, L"	</body>\n");
	fwprintf(fo, L"</html>");
	fclose(fo);
}
void wmain()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	FILE *fp = _wfopen(L"ten.csv", L"r, ccs=UTF-8");
	if (fp == NULL)
	{
		wprintf(L"Tệp mở không thành công.\n");
	}
	wchar_t buf[299];
	fgetws(buf, 299, fp);
	wprintf(L"%s\n", buf);
	DocFile(buf);
	Vietfile(buf);
	fclose(fp);

	system("pause");
}