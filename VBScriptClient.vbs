Set mouse = GetObject("new:{3eb17078-42bb-425f-adaa-e050e6b3add4}")
mouse.click "myButton"
mouse.scroll 1234
' VBScript cannot call IKeyboard as it's not ole-automation (IDispatch) compatible
