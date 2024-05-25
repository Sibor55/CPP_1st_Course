// Задача №7
// “Чтение файлов различных типов”

// 	Воспользуйтесь кодом из репозитория https://github.com/mrBelka/2023_1pm_mo/tree/main/advanced/lecture19_inheritance_practice и дополните его для чтения бинарных файлов (.binf) со следующей структурой:

// 4 байта - количество чисел N (unsigned int).
// 4*N байт - числа типа float.

// 	Чтение файлов *.bin и *.txt должно остаться рабочим. Вместо “сырых” указателей рекомендуется использовать “умные” так, где это уместно.

// N < 256 и a_i < 256, для всех i=1..N
// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
// .bin - массив данных в формате N и a_i, где i=1..N (bin)

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

class DataReader
{
protected:
    std::ifstream m_in;
    std::string m_filename;
    std::unique_ptr<uint8_t[]> m_data;
    uint8_t m_n;

public:
    DataReader(const std::string &filename) : m_filename(filename), m_n(0), m_data(nullptr) {}

    virtual ~DataReader() {}

    virtual bool Open() = 0;
    void Close()
    {
        m_in.close();
    }

    virtual void Read() = 0;
    virtual void Write() = 0;

    void GetData(uint8_t *buf, uint8_t &n)
    {
        n = m_n;
        for (int i = 0; i < m_n; i++)
            buf[i] = m_data[i];
    }
};

class TxtReader : public DataReader
{
public:
    TxtReader(const std::string &filename) : DataReader(filename) {}
    virtual ~TxtReader() {}

    bool Open() override
    {
        m_in.open(m_filename);
        return m_in.is_open();
    }

    void Read() override
    {
        int tmp;
        m_in >> tmp;
        m_n = tmp;
        m_data = std::make_unique<uint8_t[]>(m_n);
        for (int i = 0; i < m_n; i++)
        {
            m_in >> tmp;
            m_data[i] = tmp;
        }
    }

    void Write() override {}
};

class BinReader : public DataReader
{
public:
    BinReader(const std::string &filename) : DataReader(filename) {}
    virtual ~BinReader() {}

    bool Open() override
    {
        m_in.open(m_filename, std::ios::binary);
        return m_in.is_open();
    }

    void Read() override
    {
        m_in.read(reinterpret_cast<char *>(&m_n), 1);
        m_data = std::make_unique<uint8_t[]>(m_n);
        m_in.read(reinterpret_cast<char *>(m_data.get()), m_n);
    }

    void Write() override {}
};

class BinfReader : public DataReader
{
private:
    std::vector<float> m_float_data;

public:
    BinfReader(const std::string &filename) : DataReader(filename) {}
    virtual ~BinfReader() {}

    bool Open() override
    {
        m_in.open(m_filename, std::ios::binary);
        return m_in.is_open();
    }

    void Read() override
    {
        uint32_t num_floats;
        m_in.read(reinterpret_cast<char *>(&num_floats), sizeof(num_floats));
        m_n = static_cast<uint8_t>(num_floats);
        m_float_data.resize(num_floats);
        m_in.read(reinterpret_cast<char *>(m_float_data.data()), num_floats * sizeof(float));
    }

    void Write() override {}

    void GetFloatData(std::vector<float> &data)
    {
        data = m_float_data;
    }
};

std::unique_ptr<DataReader> Factory(const std::string &filename)
{
    std::string extension = filename.substr(filename.find_last_of('.') + 1);

    if (extension == "txt")
        return std::make_unique<TxtReader>(filename);
    else if (extension == "bin")
        return std::make_unique<BinReader>(filename);
    else if (extension == "binf")
        return std::make_unique<BinfReader>(filename);

    return nullptr;
}

int main()
{
    uint8_t n;
    uint8_t buf[100];

    auto Reader = Factory("input3.binf");
    if (Reader == nullptr)
        return -1;
    Reader->Open();
    Reader->Read();

    if (auto binfReader = dynamic_cast<BinfReader *>(Reader.get()))
    {
        std::vector<float> float_data;
        binfReader->GetFloatData(float_data);
        std::cout << float_data.size() << " Числа из файла бинф." << std::endl;
        for (float f : float_data)
            std::cout << f << std::endl;
    }
    else
    {
        Reader->GetData(buf, n);
        std::cout << static_cast<int>(n) << std::endl;
        for (int i = 0; i < n; i++)
            std::cout << static_cast<int>(buf[i]) << std::endl;
    }

    return 0;
}
