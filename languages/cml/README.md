# CML (Cassou Markup Language)

CML is a markup language that is used to define the structure of a CassouNet application. It is a simple language that is easy to read and write. It is used to define the structure of the application, the layout of the elements and the style of the elements.

```cml
style[id=container_style]{
  title_container{
    width=100px,
    height=50px,

    title_content{
      font_size=20px,
      font_family=Arial,
      font_color=black,
    }
  }
}

%for i = 0 to 10 {
  container[style=title_container,id=othertest]{
    title[style=title_content]{"CassouNet"}
  }
}%

```
