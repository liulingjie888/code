VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   2760
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   2760
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "求质数"
      Height          =   375
      Left            =   1800
      TabIndex        =   1
      Top             =   360
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Height          =   2655
      Left            =   360
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      Text            =   "Form1.frx":0000
      Top             =   120
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim i, j As Integer
For i = 3 To 1000 Step 2
    For j = 2 To Int(Sqr(i))
        If i Mod j = 0 Then Exit For

    Next j
    If j > Int(Sqr(i)) Then
    Text1.Text = Text1.Text & i & vbCrLf
    End If
Next i
End Sub

Private Sub Form_Load()
Text1.Text = ""
End Sub

