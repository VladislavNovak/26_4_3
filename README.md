<details open>
<summary><span style="color:tomato;font-size:16px">Class</span></summary>
<details open style="margin: 16px; outline: 1px dashed rgba(255,255,255,0.8); outline-offset: 6px;">
<summary><span style="color:tomato;font-size:12px">���������� ��������� ���������� ����� �������� �����</span></summary>

���������� ��������� ������ ���� � ���������� ���������� ������������.

���� ������������� �� ����������� ������ ��������, �������� 80 X 50 �����. 
� ���� ���� ��������� ����������, ������� ����� �������� � ��������: 
��������� ���������� ������ �������� ���� � �������, ������ � ������. 
������ � ������ ��� ���� �� ����� ���� ��������������, � ���������� �� ����� �������� �� ������� ������.

������������ ��������������� � ���������� � ������� ������:

- ������� move ��������� ������, �� ������� ���� �������� ���� �� ������. ��������� � ������ ������������ ���� ���������� �� ������.
- ������� resize ����������� �� ������������ ����� ����� ������ ����. ����� ��������� ������� ��������� � ����� �������� ��������� �� ������.
- ������� print ������� ������� ����������� �������� � �������. 0 � ��� ������� ��� ������� ����, 1 � � �����.
- ������� close ��������� ����, ����� �� ���������.

</details>

<details>
<summary><span style="color:tomato;font-size:12px">����������</span></summary>

����� Window �������� ���������� � ����. 
��� ����� ���� ������� ���� SIMPLE, � ����� ���� MONITOR. 

MONITOR �������� ���������� ���� � ����������� ��������� ��������. 
�� ����, ��� ����������� ������������� �������� � ��������. 
������ ����� ������ ���� ��� - ��� �������������

SIMPLE ����� �������� ������� (������ � ������), �� ���� � ��������, 
������� ��� ������������� �������� �� ����� ���������� ��������. 
� SIMPLE �������� ��������� �������� 
(� ������ ��� ����������� ��� changeWidth � changeHeight, �� ����� �������� � ����).

��� �� ���� ����� Screen. �� �������� vector<Window*> windows. 
������ ��������� � ���� ������� ������ ��� window->MONITOR, ������� �������� ��� ������������� Screen. 
��������� �������� - ��� ���� SIMPLE, ������� ��������� ����������� Screen::addWindow().

������ ������ �������� ����������� ���������� 
� ������ screen ������ ���������� ���� � ����������� �������� � ������ �� ���.

</details>
</details>