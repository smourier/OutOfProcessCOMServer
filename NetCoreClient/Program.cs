using OutOfProcessCOMServerLib;

namespace NetCoreClient
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var mouse = new Mouse();
            mouse.click("myBytton");
            mouse.scroll(1234);

            var keyboard = (IKeyboard)mouse;
            keyboard.pressKey("myKey");
            keyboard.releaseKey("myKey");
        }
    }
}