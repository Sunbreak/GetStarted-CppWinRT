#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Syndication;

int main()
{
    winrt::init_apartment();

    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;
    SyndicationFeed syndicationFeed = syndicationClient.RetrieveFeedAsync(rssFeedUri).get();
    // FIXME https://developercommunity.visualstudio.com/content/problem/886344/converter-lookup-fails-due-to-memory-access-violat.html
    //for (const SyndicationItem syndicationItem : syndicationFeed.Items())
    //{
    //    winrt::hstring titleAsHstring = syndicationItem.Title().Text();
    //    std::wcout << titleAsHstring.c_str() << std::endl;
    //}
    IVector<SyndicationItem> syndicationItemVector = syndicationFeed.Items();
    for (uint32_t i = 0; i < syndicationItemVector.Size(); i++)
    {
        SyndicationItem syndicationItem = syndicationItemVector.GetAt(i);
        hstring titleAsHstring = syndicationItem.Title().Text();
        std::wcout << titleAsHstring.c_str() << std::endl;
    }
}