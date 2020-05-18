VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4215
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   3150
   LinkTopic       =   "Form1"
   ScaleHeight     =   4215
   ScaleWidth      =   3150
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      Height          =   3495
      Left            =   360
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      Top             =   480
      Width           =   2295
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "100之内的勾股数"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Width           =   2295
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
Dim a, b, c As Integer

Text1.Text = ""
num = 0
For a = 1 To 98
    For b = a + 1 To 99
        c = Sqr(a ^ 2 + b ^ 2)
        If c ^ 2 = a ^ 2 + b ^ 2 And c <= 100 Then
        Text1.Text = Text1.Text & a & vbTab & b & vbTab & c & vbCrLf
        num = num + 1
        End If
    Next b
Next a
Text1.Text = Text1.Text & " 共有" & num & "组勾股数"
End Sub

